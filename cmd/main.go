package main

import (
	"encoding/json"
	"fmt"
	"net/http"

	"github.com/gorilla/mux"
)

type FileTestsResponse struct {
	DayName  string
	FileName string
}

func writeJSON(w http.ResponseWriter, status int, v any) error {
	w.Header().Set("Content-Type", "application/json")
	w.WriteHeader(status)
	fmt.Println(v)
	return json.NewEncoder(w).Encode(v)
}

func handleTestPost(w http.ResponseWriter, r *http.Request) {
	//Allow CORS here By * or specific origin
	w.Header().Set("Access-Control-Allow-Origin", "*")
	w.Header().Set("Access-Control-Allow-Headers", "Content-Type")

	response := FileTestsResponse{}
	response.DayName = r.FormValue("day-name")
	file, header, err := r.FormFile("itoa.c")
	if err != nil {
		panic(err)
	}
	defer file.Close()

	// response.FileName = strings.Split(header.Filename, ".")
	response.FileName = header.Filename
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
