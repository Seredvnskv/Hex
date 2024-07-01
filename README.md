# Hex
## The classic variant of the game Hex is played on an 11 x 11 hexagonal board:

### Rules of the game are as follows:
#### The game is played by two players (red and blue).
#### The starting player is the red player.
#### Players take turns placing a piece of their color on any unoccupied space.
#### The player who forms a continuous line connecting two edges of the board with their own color wins.

### A sequence of test cases, each starting with a drawing of the board's contents followed by a series of queries. The size of the board can vary from 1 to 11. The presence of a red (starting player) pawn is denoted by the letter "r", and a blue pawn by the letter "b". Sample boards may look like this:

                          ---
                       --<   >--
                    --< r >-<   >--
                 --< b >-< b >-< b >--
              --< r >-<   >-< r >-< r >--
           --< r >-< r >-<   >-<   >-< r >--
        --< r >-< b >-<   >-< r >-< r >-<   >--
     --< r >-<   >-< b >-<   >-<   >-< r >-<   >--
    <   >-<   >-<   >-< r >-<   >-<   >-< r >-< b >
     --<   >-< b >-< r >-< r >-<   >-< r >-<   >--
        --< r >-<   >-< b >-<   >-< r >-< r >--
           --< b >-<   >-< b >-<   >-<   >--
              --< b >-< b >-< r >-<   >--
                 --<   >-< r >-<   >--
                    --<   >-< b >--
                       --< b >--
                          ---

### A query can take the following form:
#### BOARD_SIZE - a number from the range <1;11> indicating the size of the board.
#### PAWNS_NUMBER - a number from the range <0;121> indicating the number of pawns of both players on the board.
#### IS_BOARD_CORRECT - a YES/NO response indicating whether the state of the board is correct, in other words, whether the number of pawns of one player is appropriate relative to the number of pawns of the other player.
#### IS_GAME_OVER - a YES RED/YES BLUE/NO response indicating whether (and if so, which) player has ended the game, i.e., whether they have connected two edges of the board with an uninterrupted path of their color.
#### IS_BOARD_POSSIBLE - a YES/NO response indicating whether the state of the board is possible. This means that the board is correct and that achieving such a state did not result in overlooking an earlier win by one of the players.
