#!/bin/bash

NC='\033[0m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
LIGHT_GREEN='\033[1;32m'

helpFunction()
{
   echo ""
   echo "Usage: $0 -c 42 -p A"
   echo -e "\t-c Contest identifier"
   echo -e "\t-p Contest problem"
   exit 1
}

while getopts "c:p:" opt
do
   case "$opt" in
      c ) CONTEST="$OPTARG" ;;
      p ) PROBLEM="$OPTARG" ;;
      ? ) helpFunction ;;
   esac
done

# Print helpFunction in case parameters are empty
if [ -z "$CONTEST" ] || [ -z "$PROBLEM" ]
then
   helpFunction
fi

PROBLEM_DIR="problems/$PROBLEM/$CONTEST$PROBLEM"
TARGET="$PROBLEM_DIR/main"
TESTS_DIR="$PROBLEM_DIR/tests"
INPUTS_DIR="$TESTS_DIR/inputs"
OUTPUTS_DIR="$TESTS_DIR/outputs"

for INPUT in ./$INPUTS_DIR/*
do
    TEST="${INPUT##*/}"
    ANSWER="$OUTPUTS_DIR/$TEST"
    echo -n "Test: #$TEST"
    OUT=`$TARGET < $INPUT`
    DIFF=`echo "$OUT" | diff $ANSWER -`

    if [ -z "${DIFF}" ]
    then
        echo ", verdict: ${LIGHT_GREEN}OK${NC}"
    else
        echo ", verdict: ${RED}ERROR${NC}"

        echo "${YELLOW}Input${NC}"
        cat $INPUT
        echo ""

        echo "${YELLOW}Output${NC}"
        echo "$OUT"
        echo ""

        echo "${YELLOW}Answer${NC}"
        cat $ANSWER
        echo ""

        echo "${YELLOW}Diff${NC}"
        echo $DIFF
        echo ""

        break
    fi
done
