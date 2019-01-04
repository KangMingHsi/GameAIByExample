# GameAIByExample

1. combine the method we do in obstacle avoidance and wall avoidance to make player have ability to dribble around oppenents. Also, it will dribble back when support player is behind.

2. implement one of the defend player who is close to oppenent's support player to interpose between ball and it.

3. Add the score calculation about the points whether spot is near to support player or not. Also, it is in front of controll player or not affects the score, too.

4. make the player who is in wait state also need to switch to chaseball state when the oppenent's controll player is too close to our goal.

5. calculate how much force we need when the ball arrived the destination in min acceptable velocity, and then change the force.

6. add Endurance inside PlayerBase, it will affects maxSpeed to the player. I only decrease endurance when the player is chasing ball, and recover only when in wait state.

7. add a referee. it tracks when it is in the "good distance". It will always perp to the ball's velocity as long as it is not zero, otherwise, it will be up or down relative to the ball.