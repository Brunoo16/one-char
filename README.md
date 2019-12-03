# one-char
Yet another esoteric language, inspired by brainfuck.

# To-do
- Modify/Add features keeping backwards compatibility.</br>
- Provide solution files for Visual Studio.
- Provide a few more examples.

# Commands
Just like brainfuck, there is a movable data pointer to get around. Take into account that ASCII character encoding is used for input/output.

| Command | Description |
| --- | --- |
| `a` | increments the data pointer, pointing to the next cell to the right (Each cell has 1 byte). |
| `b` | decrements the data pointer, pointing to the next cell to the left (If the data pointer wasn't incremented or is back at the initial position, this command has no effect). |
| `c` | increments the byte by 1 at the cell the data pointer is located at. |
| `d` | Decrements the byte by 1 at the cell the data pointer is located at. |
| `e` | Outputs the character representation of the current cell's byte (Assuming the data pointer is pointing to that cell). |
| `f` | Gets the user input and stores each character in a cell, starting from the one the data pointer is located at. (Does not increment the data pointer). |
| `g` | Denotes a loop. Will repeat according to the value at the cell the data pointer is located at. So, if the cell the data pointer is at has the value 8, the loop will repeat 8 times. |
| `h` | Denotes where the loop stops. |
| `i` | Sums the value of the current cell (assuming the data pointer is located there) to the value of the previous cell, storing it at the current cell. If the data pointer is at the start (wasn't incremented or was decremented until getting there), it will sum the value of the current cell to itself. |
| `j` | Subtracts the value of the current cell (assuming the data pointer is located there) to the value of the previous cell, storing it at the current cell. If the data pointer is at the start (wasn't incremented or was decremented until getting there), it will become 0. |
| `k` | Multiplies the value of the current cell (assuming the data pointer is located there) to the value of the previous cell, storing it at the current cell. If the data pointer is at the start (wasn't incremented or was decremented until getting there), it will multiply the value of the current cell by itself (basically, the number goes to the power of two). |
| `l` | Outputs the integer representation of the current cell's byte (Assuming the data pointer is pointing to that cell). |
| `m` | Swaps the value of the current cell (Where the data pointer is at) with the previous cell. This command has no effect if the data pointer was never incremented or was decremented back to the start. |
| `n` | Swaps the value of the current cell (Where the data pointer is at) with the next cell. This command has no effect if the current cell is the last (assuming there is no way to increment the data pointer). |
| `o` | Gets the user input and stores each character in a cell, starting from the one the data pointer is located at. (Sets the data pointer to the cell the last character is at). |
| `p` | Gets one byte of input only, storing the value at the current cell (where the data pointer is at). |
