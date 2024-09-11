package main

import (
	"encoding/json"
	"fmt"
	"io"
	"net/http"
	"os"
	"path/filepath"

	"github.com/gorilla/mux"
)

func writeJSON(w http.ResponseWriter, status int, v any) error {
	w.Header().Set("Content-Type", "application/json")
	w.WriteHeader(status)
	return json.NewEncoder(w).Encode(v)
}

func handleTestPost(w http.ResponseWriter, r *http.Request) {
	//Allow CORS here By * or specific origin
	w.Header().Set("Access-Control-Allow-Origin", "*")
	w.Header().Set("Access-Control-Allow-Headers", "Content-Type")

	response := FileTestsResponse{}
	filesTests := make(map[string]interface{})

	day := r.FormValue("day-name")
	dayExercises := GetDayExercises(day)
	if dayExercises == nil {
		writeJSON(w, http.StatusOK, FileTestsResponseError{Message: day + " Day not found"})
		return
	}
	response.Dayname = day
	response.Exercises = dayExercises

	for _, val := range response.Exercises {
		file, header, err := r.FormFile(val)
		if err != nil {
			continue
		}
		defer file.Close()

		filename := header.Filename
		if filepath.Ext(filename) != ".c" && filepath.Ext(filename) != ".h" {
			writeJSON(w, http.StatusOK, FileTestsResponseError{Message: "Unseported file extension " + filename})
			return
		}
		// save file
		cFilepath := "./cfiles/" + filename
		f, err := os.OpenFile(cFilepath, os.O_WRONLY|os.O_CREATE, 0666)
		if err != nil {
			writeJSON(w, http.StatusOK, FileTestsResponseError{Message: "Couldn't save file " + filename})
			return
		}
		io.Copy(f, file)

		// filesTests[filename] = []string{"ok", "ko"}
		filesTests[filename] = testcFile(day, filename, cFilepath)
		response.FilesTests = filesTests
		os.Remove("./output.txt")
	}
	if response.FilesTests == nil {
		writeJSON(w, http.StatusOK, FileTestsResponseError{Message: "Got No File From " + day})
		return
	}
	writeJSON(w, http.StatusOK, response)
}

func main() {
	r := mux.NewRouter()
	r.HandleFunc("/test", handleTestPost).Methods("POST")

	srv := &http.Server{
		Addr:    ":8090",
		Handler: r,
	}
	fmt.Println("Listening...")
	srv.ListenAndServe()

}
