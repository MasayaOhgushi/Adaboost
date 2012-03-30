#$1 learn_data $2 data number + 1 
./ada_i $1 > test
grep -A $2 "4Evaluation" test > e_test
sed -e "1d" e_test > e_test2
