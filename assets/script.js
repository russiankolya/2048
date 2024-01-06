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

        row.appendChild(tile);
    }
    board.appendChild(row);
}
