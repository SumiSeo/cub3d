#! /bin/bash

source ./vars.sh
echo -e "Please select directory to run tests on (valid || not_valid)"
read input
files_with_errors=""                                         
case "$input" in 
	valid|not_valid)
		rm $OUTPUT_FILE
		echo -e "${GREEN}Running tests...${DEFAULT}"
		cd $input
		files=$(ls)
		for file in $files; do
		$RUN_TEST "$file" 2> tmp.txt
		# if grep "in use at exit:" tmp.txt | grep -E '\b[1-9]\b'; then
		# 	echo -e "${RED}KO${DEFAULT} : Error at file $file"
		# fi
		cat tmp.txt >> ../$OUTPUT_FILE
	done
	rm tmp.txt
	echo "Done ! Results are available in $OUTPUT_FILE"
	;;
	*)
		echo "$WRONG_DIRECTORY_MESSAGE"
	;;
esac


