package main

import (
	"fmt"
	"net/http"
)

func main() {
	mux := http.NewServeMux()

	mux.HandleFunc("POST /test", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintf(w, "Hello Daddynette!")
	})
	fmt.Println("Listening...")

	http.ListenAndServe(":0890", mux)
}
