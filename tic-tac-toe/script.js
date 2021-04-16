/*
We store our game status element here to allow us to more easily 
use it later on 
*/
const gameStatus = document.querySelector('.game--status');
let inGame = true;
let currentPlayer = "X";
let playerState = ["", "", "", "", "", "", "", "", ""];
const ifWin = () => `Game Result:Player ${displayPlayer()} has won!`;
const ifDraw = () => `Game Result:draw!`;
const turn = () => `It's ${currentPlayer}'s turn`;

/*
We set the inital message to let the players know whose turn it is
*/
gameStatus.innerHTML = turn();

/*for clickable cell*/
document.querySelectorAll('.cell').forEach(cell => cell.addEventListener('click', handleClickedCell));

/*for restart button*/
document.querySelector('.game--restart').addEventListener('click', handleRestart);

function handleClickedCell(clickedCellEvent) {
    /*
    We will save the clicked html element in a variable for easier further use
    */
    const clickedCell = clickedCellEvent.target;
    /*
    Here we will grab the 'data-cell-index' attribute from the clicked cell to identify where that cell is in our grid. 
    Please note that the getAttribute will return a string value. Since we need an actual number we will parse it to an 
    integer(number)
    */
    const clickedCellIndex = parseInt(
        clickedCell.getAttribute('data-cell-index')
    );
    /* 
    Next up we need to check whether the call has already been played, 
    or if the game is paused. If either of those is true we will simply ignore the click.
    */
    if (playerState[clickedCellIndex] !== "" || !inGame) {
        return;
    }
    /* 
    If everything if in order we will proceed with the game flow
    */
    handleCellPlayed(clickedCell, clickedCellIndex);
    handleResultValidation();
}

function handleCellPlayed(clickedCell, clickedCellIndex) {
    /*
    We update our internal game state to reflect the played move, 
    as well as update the user interface to reflect the played move
    */
    playerState[clickedCellIndex] = currentPlayer;
    clickedCell.innerHTML = currentPlayer;
}

const winningStates = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6]
];
function handleResultValidation() {
    let roundWon = false;
    for (let i = 0; i <= 7; i++) {
        const winState = winningStates[i];
        let a = playerState[winState[0]];
        let b = playerState[winState[1]];
        let c = playerState[winState[2]];
        if (a === '' || b === '' || c === '') {
            continue;
        }
        if (a === b && b === c) {
            roundWon = true;
            break
        }
    }
    if (roundWon) {
        gameStatus.innerHTML = ifWin();
        inGame = false;
        return;
    }

    /* 
    We will check weather there are any values in our game state array 
    that are still not populated with a player sign
    */
    let roundDraw = !playerState.includes("");
    if (roundDraw) {
        gameStatus.innerHTML = ifDraw();
        inGame = false;
        return;
    }
    /*
    If we get to here we know that the no one won the game yet, 
    and that there are still moves to be played, so we continue by changing the current player.
    */
    handlePlayerChange();
}
function handlePlayerChange() {
    currentPlayer = currentPlayer === "X" ? "O" : "X";
    gameStatus.innerHTML = turn();
}
function handleRestart() {
    inGame = true;
    currentPlayer = "X";
    playerState = ["", "", "", "", "", "", "", "", ""];
    gameStatus.innerHTML = turn();
    document.querySelectorAll('.cell')
        .forEach(cell => cell.innerHTML = "");
}
/*
function displayPlayer() {
    let con = require('./connection');
    if (currentPlayer == "X") {
        con.connect(function (err) {
            if (err) throw err;
            con.query("SELECT playeroneun FROM player WHERE idplayer=1", function (err, result) {
                if (err) throw err;
                return result;
            });
        });
    } else {
        con.connect(function (err) {
            if (err) throw err;
            con.query("SELECT playertwoun FROM player WHERE idplayer=1", function (err, result) {
                if (err) throw err;
                return result;
            });
        });
    }
}
*/