<img width="300" alt="Logo (4)" src="https://github.com/user-attachments/assets/a8c3e7ef-c88a-4c7a-8d6c-3ff36cd6a040" />

# bProg

bProg (byte Programming Interpreter) is a programming interpreter designed for byteOS. It currently features semicolon support and executing byteOS commands.
It can also output to USART/UART in normal/loop mode.

Functions:

bProg has 3 functions as of right now.

output(uart) - Output text to USART/UART. 
Example:
In file hello.bp 
`output(uart) hi`
This will output hi into USART/UART.

output(uart, loop) - Output text to USART/UART in a breakable loop.
Example:
In file hello.bp 
`output(uart, loop) hi`
This will output hi every time you press enter until you type exit and press enter into USART/UART.

execute(commands) - Execute byteOS commands
Example:
In file echo.bp 
`execute(commands) echo hi`
This will execute echo hi, outputting `hi`

That is all of the functions.
As mentioned before, bProg supports semicolons.
Example:
In file echo.bp 
`execute(commands) echo hi;output(uart) bye`
This will execute echo hi, outputting `hi` AND output 'bye' to USART/UART.

There is also one quirk, you mustn't use a space after a semicolon. 

This will work:

`execute(commands) echo hi;output(uart) bye`

This won't:

`execute(commands) echo hi; output(uart) bye`

This is because instead of running
`echo hi`
and
`output(uart) bye`
it will run
`echo hi`
and
` output(uart) bye` with a space at the start.

That is all, thank you for reading.





