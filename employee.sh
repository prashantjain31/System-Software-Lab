#!/bin/bash
DATA_FILE="employee_records.txt"


function addEmployee() {
	echo
	read -p "Enter The Employee ID: " id
	read -p "Enter The Employee Name: " name
	read -p "Enter The Employee Phone: " phone
	if grep -q "^$id .* .*" $DATA_FILE; then
		echo "Employee Already Exists"
	else 
		echo "$id $name $phone" >> "$DATA_FILE"
		echo "Employee Added Successfully"
	fi
}

function listRecords() {
	echo
	echo "List Of All Employees: "
	cat "$DATA_FILE"
	echo
}

function searchEmployee() {
	echo 
	read -p "Enter the Employee ID: " id
	grep  "^$id .* .*" $DATA_FILE
        echo	

}

function sortEmployee() {
	echo
	sort -t ' ' -k1n  $DATA_FILE > tmpfile.txt
	mv tmpfile.txt $DATA_FILE
	echo "Record Sorted Successfully"
	echo
}

function deleteEmployee() {
	echo
	read -p "Enter the Employee ID: " id
	grep -v "^$id .* .*" $DATA_FILE > tmpfile.txt
	mv tmpfile.txt $DATA_FILE
	echo "Employee Deleted Successfully"
	echo
}

while true : 
do
	echo
	echo "1: Add employee"
	echo "2. Delete Employee"
	echo "3. Search Employee"
	echo "4. Display Employee Details"
	echo "5. Sorted Employee List"
	echo "6. List all records"
	echo "7. Exit"
	echo

	read -p "Enter your choice: " choice

	case $choice in
		1) addEmployee;;
		2) deleteEmployee;;
		3) searchEmployee;;
#		4) displayEmployee;;
		5) sortEmployee;;
		6) listRecords;;
		7) break;;
		*) echo "Please try again";;
	esac

done


