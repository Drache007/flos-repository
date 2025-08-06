let playerScore = 0;
let computerScore = 0;

let playerChoice;
let computerChoice;

const choices = ["rock", "paper", "scissors"];

window.onload = function() {
    for (let i = 0; i < 3; i++) {
        // create buttons for choices
        let choice = document.createElement("img");
        choice.id = choices[i];
        choice.src = "images/" + choices[i] + ".png";
        choice.addEventListener("click", play);
        document.getElementById("choices").append(choice);
    }
}

function play() {
    // write out player Choice
    playerChoice = this.id;
    document.getElementById("playerChoice").src = "images/" + playerChoice + ".png";

    // generate computer choice
    let randIndex = Math.floor(Math.random() * 3);
    computerChoice = choices[randIndex];
    document.getElementById("computerChoice").src = "images/" + computerChoice + ".png";

    //see who won
    if ((playerChoice == "rock" && computerChoice == "scissors") || (playerChoice == "paper" && computerChoice == "rock") || (playerChoice == "scissors" && computerChoice == "paper")) {
        playerScore++;
    } else if (playerChoice != computerChoice) {
        computerScore++;
    }

    //write out new score
    document.getElementById("playerScore").innerText = playerScore;
    document.getElementById("computerScore").innerText = computerScore;
}