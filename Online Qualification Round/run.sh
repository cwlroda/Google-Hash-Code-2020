#!/bin/bash

echo "Cleaning temporaries and output files"
make clean
rm -r bin
rm -r test/output
echo ""
echo "Force building program"
mkdir bin
mkdir test/output
make all

for i in test/input/*.in; do
    echo ""
    echo "Testing: ${i}"
    BASENAME=$(basename $i .in);
    touch test/output/$BASENAME.out
    ./bin/solver ${i} test/output/$BASENAME.out
    echo "Success!"
done

echo ""