class Solution {
public:
    pair<int, int> getCoordinates(int cellNumber, int boardSize) {
        int colIndex = (cellNumber - 1) % boardSize;
        int rowIndex = (cellNumber - 1) / boardSize;
        int actualCol;
        if (rowIndex % 2 == 0) {
            actualCol = colIndex;
        } else {
            actualCol = boardSize - colIndex - 1;
        }
        return make_pair(boardSize - rowIndex - 1, actualCol);
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int boardSize = board.size();
        vector<bool> visited(boardSize * boardSize + 1, false);

        queue<pair<int, int>> bfsQueue;
        bfsQueue.push(make_pair(1, 0)); 
        visited[1] = true;

        while (!bfsQueue.empty()) {
            pair<int, int> current = bfsQueue.front();
            bfsQueue.pop();

            int cellNumber = current.first;
            int moveCount = current.second;

            if (cellNumber == boardSize * boardSize)
                return moveCount;

            for (int diceRoll = 1; diceRoll <= 6; diceRoll++) {
                int nextCell = cellNumber + diceRoll;
                if (nextCell > boardSize * boardSize)
                    break;

                pair<int, int> coordinates = getCoordinates(nextCell, boardSize);
                int row = coordinates.first;
                int col = coordinates.second;

                int destination = board[row][col] == -1 ? nextCell : board[row][col];
                if (!visited[destination]) {
                    bfsQueue.push(make_pair(destination, moveCount + 1));
                    visited[destination] = true;
                }
            }
        }

        return -1;
    }
};