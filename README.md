# ADIP-Final-Project
**We will automatically assemble scattered puzzle together, and then we will extract the road through 
the satellite image, then using the extracted road to make the navigation function**


![image](https://user-images.githubusercontent.com/91001059/166906406-2611bee5-4e3d-4a58-9149-30259cbff649.png)
* we are using MSE to caculate the puzzle boundary simiraity
* then using image stiching to stich every puzzle

![image](https://user-images.githubusercontent.com/91001059/166906583-b2a05445-103b-402c-bf21-372bc9025e98.png)
* first, We using k-means clustering to cluster the color to k categorized
![image](https://user-images.githubusercontent.com/91001059/166906957-d177e11b-6e17-48bf-9bc2-6c7811bca9f2.png)
* Then using HSV to extract certain road colors(R:110~142,G:106~144, B:115~139)<- RGB
* using Morphological dilation makes objects more visible and fills in small holes in objects
![image](https://user-images.githubusercontent.com/91001059/166906635-6361bf7a-7afb-45ec-94f4-2ec2723619cb.png)
* using BFS to find the closet navigation 



