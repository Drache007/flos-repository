let computerScore = 0;
let playerScore = 0;
let playerSymbol = "X";
let computerSymbol = "O";
let gameOver = false;
var board;
var checkDraw = false;

window.onload = function() {
    initializeGame();
}

function initializeGame() {
    gameOver = false;
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
            if (i < 2) {
                tile.classList.add("horizontalLine");
            }
            if (j < 2) {
                tile.classList.add("verticalLine");
            }
            tile.addEventListener("click", makeMove);
            document.getElementById("board").append(tile);
        }
    }

    if (computerSymbol == "X") {
        generateComputerMove();
    }
}

function makeMove() {
    if (gameOver) {
        return;
    }
    
    let coords = this.id.split("-");
    let row = parseInt(coords[0]);
    let col = parseInt(coords[1]);

    if (board[row][col] != " ") {
        return;
    }

    board[row][col] = playerSymbol;
    this.innerText = playerSymbol;

    checkGameOver(playerSymbol);
    if (gameOver) {
        removeBoard();
        initializeGame();
        return;
    }
    generateComputerMove();
    checkGameOver(computerSymbol);
    if (gameOver) {
        removeBoard();
        initializeGame();
    }
}

function generateComputerMove() {
    if (gameOver) {
        return;
    }
    let freeSpaces = [];
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            if (board[i][j] == " ") {
                freeSpaces.push(i.toString() + "-" + j.toString());
            }
        }
    }
    let choice = Math.floor(Math.random() * freeSpaces.length);
    document.getElementById(freeSpaces[choice]).innerText = computerSymbol;
    let coords = freeSpaces[choice].split("-");
    let row = parseInt(coords[0]);
    let col = parseInt(coords[1]);
    board[row][col] = computerSymbol;
}

function checkGameOver(activePlayer) {
    // check vertically
    for (let i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            if (board[i][0] != " ") {
                for (let j = 0; j < 3; j++) {
                    document.getElementById(i.toString() + "-" + j.toString()).classList.add("winner");
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
                    document.getElementById(j.toString() + "-" + i.toString()).classList.add("winner");
                    gameOver = true;
                }
            }
        }
    }
    // check main diagonal
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        if (board[0][0] != " ") {
            for (let i = 0; i < 3; i++) {
                document.getElementById(i.toString() + "-" + i.toString()).classList.add("winner");
                gameOver = true;
            }
        }
    }
    // check second diagonal
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        if (board[0][2] != " ") {
            for (let i = 0; i < 3; i++) {
                document.getElementById(i.toString() + "-" + (2 - i).toString()).classList.add("winner");
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
        checkDraw = true;
    }
    //update Scores
    if (gameOver && !checkDraw) {
        let winner = activePlayer;
        if (winner == playerSymbol) {
            playerScore++;
        }
        if (winner == computerSymbol) {
            computerScore++;
        }
        checkDraw = false;
    }
    // write Out Scores
    document.getElementById("playerScore").innerText = "Your Score: " + playerScore.toString();
    document.getElementById("computerScore").innerText = "Computer Score: " + computerScore.toString();
}

function removeBoard() {
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            let elementToEliminate = document.getElementById(i.toString() + "-" + j.toString());
            elementToEliminate.remove();
        }
    }
}