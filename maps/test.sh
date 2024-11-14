#! /bin/bash

source ./vars.sh                             
rm $OUTPUT_FILE
echo -e "${GREEN}Running tests...${DEFAULT}"
cd not_valid
files=$(ls)
for file in $files; do
	echo -e "test : $file" >> ../$OUTPUT_FILE
	$RUN_TEST "$file" 2> tmp.txt
	cat tmp.txt >> ../$OUTPUT_FILE
	echo -e >> ../$OUTPUT_FILE
done
rm tmp.txt
echo "Done ! Results are available in $OUTPUT_FILE"
