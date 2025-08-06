var board;
let playerX = "X";
let playerO = "O";
let activePlayer = playerX;
let gameOver = false;

window.onload = function() {
    createBoard(); 
}

function createBoard() {
    board = [
        [" ", " ", " "],
        [" ", " ", " "],
        [" ", " ", " "]
    ];
    
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            let tile = document.createElement("div");
            tile.classList.add("tile");
            tile.id = i.toString() + "-" + j.toString();
            if (i == 0 || i == 1) {
                tile.classList.add("bottomLine");
            }
            if (j == 0 || j == 1) {
                tile.classList.add("rightLine");
            }
            tile.addEventListener("click", makeMove);
            document.getElementById("board").append(tile);
        }
    }
}

function makeMove() {
    if (gameOver) {
        return;
    }
    // get coordinates
    let coords = this.id.split("-");
    let row = parseInt(coords[0]);
    let col = parseInt(coords[1]);
    // check if empty
    if (board[row][col] != " ") {
        return;
    }
    // write out player input
    board[row][col] = activePlayer;
    this.innerText = activePlayer;
    //alternate active player
    if (activePlayer == playerX) {
        activePlayer = playerO;
    } else {
        activePlayer = playerX;
    }
    checkGameOver();
}

function checkGameOver() {
    // check vertically
    for (let i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            if (board[i][0] != " ") {
                for (let j = 0; j < 3; j++) {
                    document.getElementById(i.toString() + "-" + j.toString()).id = "winner";
                    gameOver = true;
                }
            }
        }
    }
    // check horizontally
    for (let i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            if (board[0][i] != " ") {
                for (let j = 0; j < 3; j++) {
                    document.getElementById(j.toString() + "-" + i.toString()).id = "winner";
                    gameOver = true;
                }
            }
        }
    }
    // check main diagonal
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        if (board[0][0] != " ") {
            for (let i = 0; i < 3; i++) {
                document.getElementById(i.toString() + "-" + i.toString()).id = "winner";
                gameOver = true;
            }
        }
    }
    // check second diagonal
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        if (board[0][2] != " ") {
            for (let i = 0; i < 3; i++) {
                document.getElementById(i.toString() + "-" + (2 - i).toString()).id = "winner";
                gameOver = true;
            }
        }
    }
    // check for tie
    let counter = 0;
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            if (board[i][j] == " ") {
                counter++;
            }
        }
    }
    if (counter == 0) {
        gameOver = true;
    }
}