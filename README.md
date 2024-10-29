# cub3D
The object of this project is creating 3D game with raycasting. Raycasting is a fake/pseudo effect to create 3D game from 2D design. Based on 2d, rays give information regarding wall's columns(ex: heights and distances). Once we obtain this information, we have to calculate and design 3D with DDA algorithms.

# Challenges
* Create 2d environment with minilibx libraries
* Cast rays by drawing lines on 2dimensions.
* Get the distance and render the walls pixel by pixel
* Bind key events to move player's point of view
* Rerender walls based on the key events

## create 2d environment with minilibx
Parse map information and put image based on map. To do that, we need column and row sizes. Also, current window size should be needed. But this can be calculated easily by multiplying current tile and column length.

## raycasting

