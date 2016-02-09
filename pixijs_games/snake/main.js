(function() {
var width = 480;
var height = 480;
var figs = 'figs/';


var stage = new PIXI.Stage(0x00000);

var renderer = new PIXI.CanvasRenderer(width, height);
document.body.appendChild(renderer.view);

var snake = new PIXI.Sprite(
       PIXI.Texture.fromImage(figs + "sn.png") 
);

snake.anchor.x = .5;
snake.anchor.y = .5;
snake.position.x = width / 2;
snake.position.y = height / 2;

stage.addChild(snake);

document.addEventListener('keydown', onKeyDown);

requestAnimationFrame(animate);
function animate() {
    requestAnimationFrame(animate);
    // snake.x += .5;
    renderer.render(stage);
}

function onKeyDown(key) {
    if(key.keyCode === 37)
        snake.x -= 0.1;
    if(key.keyCode === 39)
        snake.x += 0.1;
    console.log('Pressed key');
}
})();
