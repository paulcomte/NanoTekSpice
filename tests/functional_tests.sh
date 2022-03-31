#!/usr/bin/env bash
status=0

simple_diff () {
    echo -n "$4 > "
    eval "echo -ne \"$1\" | ../nanotekspice \"$2\" 1> .tekspice_output" &> /dev/null
    local tekspice_status=$?
    eval "echo -ne \"$3\" > .expected_output" &> /dev/null
    local expected_status=$?
    if [ $tekspice_status -eq 139 ] || [ $tekspice_status -eq 124 ]; then
        echo -e "\e[31mKO: Crashed\e[0m"
        status=1
    else
        eval "diff <(head -n 25 .tekspice_output) <(head -n 25 .expected_output) &> .diff_output"
        diff_status=$?
        if [ $diff_status -eq 0 ];then
            echo -e "\e[32mPASSED\e[0m"
        else
            echo -e "\e[31mKO: different output;"
            eval "cat .diff_output"
            echo -e "\e[0m"
            status=1
        fi
        eval "rm -f .diff_output"
    fi
    eval "rm -f .tekspice_output"
    eval "rm -f .expected_output"
}

simple_diff_status() {
    echo -n "$4 > "
    eval "echo -ne \"$1\" | ../nanotekspice \"$2\"" &> /dev/null
    local tekspice_status=$?
    if [ $tekspice_status -eq $3 ]; then
        echo -e "\e[32mPASSED\e[0m"
        status=1
    else
        echo -e "\e[31mKO: Crashed\e[0m"
        echo -e "\e[31mKO: Different exit status;"
        echo -e "\e[31mK0 Expected:" $3 "but got" $tekspice_status
        echo -e "\e[0m"
        status=1
    fi
}

echo -e "\e[1m\e[34m# MAKE\e[0m"

eval "make --directory ../" >/dev/null 2>&1
make_status=$?
echo -n "make > "
if [ $make_status -eq 0 ];then
    echo -e "\e[32mPASSED\e[0m"
else
    echo -e "\e[31mKO: Can't build NanoTekSpice, exit.\e[0m"
    exit 1
fi

echo -e "\n\e[1m\e[34m# BASIC FILE HANDLING\e[0m"

simple_diff_status "" "" 84 "No file"
simple_diff_status "" "test" 84 "Incorrect extension"
simple_diff_status "" ".nts" 84 "Too short file name"
chmod 0 no_permission.nts
simple_diff_status "" "no_permission.nts" 84 "No permission to read the file"
simple_diff_status "" "no_links.nts" 84 "no links"
simple_diff_status "" "no_chipsets.nts" 84 "no chipset"
simple_diff_status "" "unknown_input.nts" 84 "unknown input name"
simple_diff_status "" "unknown_type.nts" 84 "unknown chipset type"
simple_diff_status "" "all_valid.nts" 0 "correct nts file"

echo -e "\n\e[1m\e[34m# COMMANDS\e[0m"
simple_diff "di" "all_valid.nts" "> > " "unknown command"
simple_diff "display" "all_valid.nts" "> tick: 0\ninput(s):\n  in: U\noutput(s):\n  out: U\n> " "valid display"
simple_diff "simulate\ndisplay" "all_valid.nts" "> > tick: 1\ninput(s):\n  in: U\noutput(s):\n  out: U\n> " "valid tick number"
simple_diff "in=1\ndisplay" "all_valid.nts" "> > tick: 0\ninput(s):\n  in: U\noutput(s):\n  out: U\n> " "Input: U because absence of the absence of simulate"
simple_diff "in=1\nsimulate\ndisplay" "all_valid.nts" "> > > tick: 1\ninput(s):\n  in: 1\noutput(s):\n  out: 1\n> " "Input: 1 and Output: 1"

echo -e "\n\e[1m\e[34m# GATES\e[0m"
echo -e "\n  \e[2m\e[34m# AND GATE\e[0m"
simple_diff "in_01=0\nin_02=0\nin_05=0\nin_06=0\nin_08=0\nin_09=0\nin_12=0\nin_13=0\nsimulate\ndisplay" "and_gate.nts" "> > > > > > > > > > tick: 1\ninput(s):\n  in_01: 0\n  in_02: 0\n  in_05: 0\n  in_06: 0\n  in_08: 0\n  in_09: 0\n  in_12: 0\n  in_13: 0\noutput(s):\n  out_03: 0\n  out_04: 0\n  out_10: 0\n  out_11: 0\n> " "X=0 Y=0 | Out=0"
simple_diff "in_01=1\nin_02=0\nin_05=1\nin_06=0\nin_08=1\nin_09=0\nin_12=1\nin_13=0\nsimulate\ndisplay" "and_gate.nts" "> > > > > > > > > > tick: 1\ninput(s):\n  in_01: 1\n  in_02: 0\n  in_05: 1\n  in_06: 0\n  in_08: 1\n  in_09: 0\n  in_12: 1\n  in_13: 0\noutput(s):\n  out_03: 0\n  out_04: 0\n  out_10: 0\n  out_11: 0\n> " "X=1 Y=0 | Out=0"
simple_diff "in_01=0\nin_02=1\nin_05=0\nin_06=1\nin_08=0\nin_09=1\nin_12=0\nin_13=1\nsimulate\ndisplay" "and_gate.nts" "> > > > > > > > > > tick: 1\ninput(s):\n  in_01: 0\n  in_02: 1\n  in_05: 0\n  in_06: 1\n  in_08: 0\n  in_09: 1\n  in_12: 0\n  in_13: 1\noutput(s):\n  out_03: 0\n  out_04: 0\n  out_10: 0\n  out_11: 0\n> " "X=1 Y=0 | Out=0"
simple_diff "in_01=1\nin_02=1\nin_05=1\nin_06=1\nin_08=1\nin_09=1\nin_12=1\nin_13=1\nsimulate\ndisplay" "and_gate.nts" "> > > > > > > > > > tick: 1\ninput(s):\n  in_01: 1\n  in_02: 1\n  in_05: 1\n  in_06: 1\n  in_08: 1\n  in_09: 1\n  in_12: 1\n  in_13: 1\noutput(s):\n  out_03: 1\n  out_04: 1\n  out_10: 1\n  out_11: 1\n> " "X=1 Y=1 | Out=1"

exit $status