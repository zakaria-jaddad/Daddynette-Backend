package main

type FileTestsResponse struct {
	Dayname    string
	Exercises  []string
	FilesTests map[string][]string
}

type FileTestsResponseError struct {
	Message string
}
