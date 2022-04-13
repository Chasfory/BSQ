#!/usr/bin/env bash

test()
{
    cat $2 &> .expected
    ./bsq $1 &> .got
    diff .expected .got
    if [[ $? == 0 ]]
    then
        echo "it's good"
    else
        echo "segmend fault"
    fi
}

test ./tests/tests_maps/maps_unsolved/Map1 ./tests/tests_maps/maps_solved/Map1
test ./tests/tests_maps/maps_unsolved/Map2 ./tests/tests_maps/maps_solved/Map2

rm -f .expected
rm -f .got