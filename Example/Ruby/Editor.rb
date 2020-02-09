# Contributed by Gnome

prompt = ""
file_name = ""
buffer = []
verbose = false

loop do

    print prompt
    input = gets

    case input[0]
    when "p"
        # Prompt
        (input.split(" ").length == 1) ? prompt = "* " : prompt = "#{input.split(" ")[1]} "

    when "h"
        # Help
        verbose = !verbose

    when "o"
        # Open a file
        if input.split(" ").length == 1
            puts "No file name provided." if verbose
        else
            file_name = input.split(" ")[1]
            File.exists?(file_name) ? buffer = File.read(file_name).split : File.new(file_name, "w")
            puts "File opened." if verbose
        end

    when "l"
        # List the buffer
        (1..buffer.length).each { |i| puts "#{i.to_s.ljust(8)}#{buffer[i - 1]}" }

    when "a"
        # Append to the buffer
        loop do
            line = gets
            break if line.start_with? "."
            buffer << line
        end

    when "w"
        # Write the buffer to file
        if file_name != ""
            file = File.open(file_name, "w")
            buffer.each { |line| file.write "#{line}\n" }
            file.close
            puts "File written." if verbose
        else
            puts "File name missing." if verbose
        end

    end

    break if input[0] == "q"
end

puts "Bye!"