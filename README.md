# ft_minishell2

* Termcaps
  * KEY_CTRL_D     Quit shell or delete letter
  * KEY_UP         History up
  * KEY_DOWN       History down
  * KEY_RIGHT      Move cursor to right
  * KEY_LEFT       Move cursor to left
  * KEY_BACK_SPACE Delete befor cursor
  * KEY_DELETE     Delele on cursor
  * KEY_END        Move cursor to end
  * KEY_HOME       Move cursor to begin
  * KEY_ALT_UP     Move cursor to line up
  * KEY_ALT_DOWN   Move curdor to line down
  * KEY_ALT_RIGHT  Move cursor to end of next word
  * KEY_ALT_LEFT   Move cursor to begin of previous word
* Parenthesis Scope
  * "
  * '
  * `
  * (
  * [
  * {
* Lexer
* Parser
  * Create recusive tree for sub-commands
* Redirection
  * Multi-Pipe
  * Right
  * Double right
  * Left
* Bultins
  * cd
  * env
  * setenv
  * unsetenv
  * exit
* Execve tree
