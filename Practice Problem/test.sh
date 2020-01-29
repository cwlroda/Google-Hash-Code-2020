#!/bin/bash

echo "Cleaning temporaries and output files"
make clean
echo ""
echo "Force building program"
make all

for i in test/in/*.in; do
    echo ""
    echo "Testing: ${i}"
    BASENAME=$(basename $i .in);
    touch test/out/$BASENAME.out
    ./bin/pizza ${i} test/out/$BASENAME.out
    echo "Success!"
done

echo ""

