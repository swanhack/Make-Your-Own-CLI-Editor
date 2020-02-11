defmodule FileEditor do
  defstruct name: nil, lines: nil

  def new(name, lines \\ []) do
    %FileEditor{name: name, lines: lines}
  end

  def append_line(file_editor, lines) do
    %FileEditor{file_editor | lines: file_editor.lines ++ lines}
  end

  def insert_line(file_editor, line, index) do
    %FileEditor{file_editor | lines: List.insert_at(file_editor.lines, index, line)}
  end

  def delete_line(file_editor, index) do
    %FileEditor{file_editor | lines: List.delete_at(file_editor.lines, index)}
  end

  def edit_line(file_editor, line, index) do
    lines = 
      List.delete_at(file_editor.lines, index)
      |> List.insert_at(index, line)
    %FileEditor{file_editor | lines: lines}
  end

  def print_file(file_editor) do
    numbered_lines = Enum.zip(0..length(file_editor.lines), file_editor.lines)
    Enum.map(numbered_lines, fn {x, y} -> IO.puts(Integer.to_string(x) <> " " <> y) end)
    file_editor
  end

  def open(name) do
    lines =
      name
      |> File.stream!()
      |> Stream.map(&String.replace(&1, "\n", ""))
      |> Enum.reduce([], fn x, y -> y ++ [x] end)
    FileEditor.new(name, lines)
  end

  def write(file_editor) do
    File.write(file_editor.name, Enum.map(file_editor.lines, fn x -> x <> "\n" end))
  end
end