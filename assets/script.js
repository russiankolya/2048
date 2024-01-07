const SIZE = 4

let board = document.getElementById("board")

for (let i = 0; i < SIZE; i++) {
    let row = document.createElement("div");
    row.setAttribute("class", "board-row");

    for (let j = 0; j < SIZE; j++) {
        let tile = document.createElement("div");

        let tile_id = "tile" + i + j;

        tile.setAttribute("id", tile_id);
        tile.setAttribute("class", "tile");

        tile.style.width = String((100 - (3 * SIZE)) / SIZE - 1) + "vmin";
        tile.style.height = String((100 - (3 * SIZE)) / SIZE - 1) + "vmin";

        row.appendChild(tile);
    }
    board.appendChild(row);
}

function updateTile(i, j, value, color) {
    let tile = document.getElementById("tile" + i + j)
    tile.style.backgroundColor = color;
    if (value === 0) {
        tile.innerHTML = "";
    } else {
        tile.innerHTML = String(value);
    }
}
