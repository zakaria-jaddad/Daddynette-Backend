package main

type FileTestsResponse struct {
	Status     bool
	Dayname    string
	Exercises  []string
	FilesTests map[string]interface{}
}

type FileTestsResponseError struct {
	Status  bool
	Message string
}
