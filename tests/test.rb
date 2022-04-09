#!/usr/bin/env ruby

def print_in_color txt, color, line_break
    color = "\033[0;30m" if color == 'black'
    color = "\033[0;31m" if color == 'red'
    color = "\033[0;32m" if color == 'green'
    color = "\033[0;33m" if color == 'yellow'
    color = "\033[0;34m" if color == 'blue'
    color = "\033[0;35m" if color == 'purple'
    color = "\033[0;36m" if color == 'cyan'
    color = "\033[0;37m" if color == 'white'
    printf("#{color}");
    puts  txt if line_break == true
    print txt if line_break == false
    printf("\033[0m");
end

system "make && clear"

NBR_OF_TEST = 1

test_1 = `./tetris -d 120 -D --key-turn=32 -p 112 | cat -e`
expected_1 = File.read("tests/expected/1.txt")

system "clear"
print_in_color("| START  TEST |", "cyan", true)
for i in 1..NBR_OF_TEST

    if test_1 == expected_1
        print_in_color("|-> test #{i} passed...", "green", true)
    else
        print_in_color("|-> test #{i} failed:", "red", true)
        print_in_color("| EXPECTED:\n#{expected_1}", "purple", true)
        print_in_color("| GOT:\n#{test_1}", "yellow", true)
    end

end
print_in_color("|     END     |", "cyan", true)
