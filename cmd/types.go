package main

type FileTestsResponse struct {
	Dayname    string
	Exercises  []string
	FilesTests map[string]interface{}
}

type FileTestsResponseError struct {
	Message string
}
