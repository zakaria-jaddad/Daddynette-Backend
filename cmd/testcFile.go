package main

import (
	"os"
	"os/exec"
)

var KO string = "exit status 1"
var OK string = "exit status 0"

/*
removeFile removes file based on the given filepath
also removes file compile a.out file and other uessesery files used to test
*/
func removeFile(filepath string) error {
	err := os.Remove(filepath)
	os.Remove("./a.out")
	if err != nil {
		return err
	}
	return nil
}

func testcFile(day string, filename string, cFilepath string) map[string]interface{} {
	tests := make(map[string]interface{})

	testFilePath := "../ctests/" + day + "/" + "ft_putchar.test.c"
	// Compile the C file
	cmd := exec.Command("gcc", testFilePath)
	err := cmd.Run()
	if err != nil {
		os.Remove(cFilepath)
		tests["status"] = "Does not compile"
		tests["result"] = ""
		return tests
	}

	cmd = exec.Command("./a.out")
	output, err := cmd.CombinedOutput()
	if err != nil {
		removeFile(cFilepath)
		if err.Error() == KO {
			tests["result"] = string(output)
			tests["status"] = "KO"
			return tests
		}
		tests["status"] = err.Error()
		tests["result"] = ""
		return tests
	}
	removeFile(cFilepath)
	tests["status"] = "OK"
	tests["result"] = string(output)
	return tests
}
