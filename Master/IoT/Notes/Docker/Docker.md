Docker is a platform designed to help developers build, share and run container applications.
What is a container?
A container is a way to package application with all the necessary dependencies and configuration; they are portable artifact (easily shared and moved around)
portable + contains all the package necessary -> develop in an efficient wat

Container live in a container repository, special storage for containers:
- private repositories
- public repository (DockerHub), where you can find every application image

Why containers? 
Before docker every developer of the team had to install package on own laptop with different process installation depending on OS. 
With container we haven't to install all dependecies and package on our OS because the container are isolated enviroment packaged with all needed configuration:
- one universal command to install the app
- run same app with 2 different versions

With Container Developers and Operations (DevOps) work together to package the application in a container, with no environmental configuration needed on server (only Docker Runtime to manage the containers)



A container is composed by a layers of images:
1. At the bottom we have linux base image (small size)
2. Application Layer


Docker image is the actual package, so the application with all the configuration and dependecies and is the artifact that can be moved around (not running). While container is component that start the application, creating the enviroment (is the running enviroment for an image):
- Virtual File system
- enviroment variables


Docker virtualize only application layer and use kernel of the machine where is installed, while VM virtualize application layer and kernel layer:
- Docker image much smaller
- Docker containers start and run much fast 
- VM of any OS can run on any OS host (also with Docker)

Workflow with Docker


Develop app on our local machine that use mongoDB to store data; in order to do that we use a docker container with a mongoDB image inside.

Commit on git that trigger some CI tool like Jenkins

Jenkins create a Docker Image of our JS Application and push it on private docker repository

With Jenkins or an another tools Development Server pulls the image of JS Application from our private docker repository and also the image of MongoDB from DOCKER hub that our app depend.



with docker-compose we can create a structured file to manage more than one container without spend time to run useless commands

```powershell
$ docker-compose -f 'file'
```