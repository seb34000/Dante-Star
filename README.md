# Dante Star
 Maze generator and solver

- Go to the root of the repository with terminal
- Use "make re" command

For generate new maze:

- Use "./generator/generator [line] [cols] [perfect]" -> argument perfect is optionnal use for generate perfect maze, without this agument imperfect maze generated.

For Solving maze:

- Use generator to generate new maze in file: "./generator/generator [line] [cols] [perfect (optionnal)] > [your output file]"
- Now you can use "./solver/solver [your maze file]"