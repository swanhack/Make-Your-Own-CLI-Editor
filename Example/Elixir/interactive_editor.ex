defmodule InteractiveEditor do
  import FileEditor

  defstruct file: nil

  def start do
    interactive_editor(InteractiveEditor.new)
  end

  def new do
    %InteractiveEditor{file: nil}
  end

  def interactive_editor(ie) do
    input = String.replace(IO.gets(": "), "\n", "")
    ie = case String.first(input) do
      "h" -> 
        IO.puts("Commands:
            h: Prints this text.
            a: Appends to the current file.
            o <filename>: Opens a file named filename.
            c <filename>: Creates a new file named filename.
            i <index>: Inserts a line at index.
            e <index>: Edits line number index.
            d <index>: Deletes line number index. 
            p: Prints the contents of the file.
            n: Prints the name of the file.
            w: Writes the currently open file.
        ")
      "a" -> 
        IO.puts("Type `EOF` to end input.")
        lines = input_loop([])
        %InteractiveEditor{file: FileEditor.append_line(ie.file, lines)}
      "o" ->
        file =
          input
          |> String.split(" ")
          |> List.last()
          |> FileEditor.open()
        FileEditor.print_file(file)
        %InteractiveEditor{file: file}
      "c" -> 
        file =
          input
          |> String.split(" ")
          |> List.last()
          |> FileEditor.new()
        %InteractiveEditor{file: file}
      "i" ->
        line = input_line()
        %InteractiveEditor{file: FileEditor.insert_line(ie.file, line, extract_int(input))}
      "e" ->
        line = input_line()
        %InteractiveEditor{file: FileEditor.edit_line(ie.file, line, extract_int(input))}
      "d" ->
        %InteractiveEditor{file: FileEditor.delete_line(ie.file, extract_int(input))}
      "p" -> 
        FileEditor.print_file(ie.file)
        ie
      "w" ->
        FileEditor.write(ie.file)
        ie
      "n" -> 
        IO.puts(ie.file.name)
        ie
      _ -> IO.puts("Invalid command. Try again.")
    end
    interactive_editor(ie)
  end

  def input_loop(lines) do
    input = IO.gets("")
    case input do
      "EOF\n" -> lines
      _ -> input_loop(lines ++ [String.replace(input, "\n", "")])
    end
  end

  def input_line do
    String.replace(IO.gets(""), "\n", "")
  end

  def extract_int(input) do
    input
    |> String.last()
    |> String.to_integer()
  end
end