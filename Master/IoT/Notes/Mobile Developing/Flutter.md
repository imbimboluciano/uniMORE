Flutter is a rich UI open-source framework developed by Google.
Framework -> not only a programming language but it is a collection of tool.

Flutter is based on an open source programming language called Dart
```powershell
$ flutter doctor #to check enviroment
$ flutter create "appname"
$ flutter pub add "dependecies"
```


- Stateless widget -> it can't be contain mutuable data
- Stateful widget -> keep the data, information after a hot reload (it can rewrite itself)


To interact with our homepage we have to implement a Scaffold inside out homepage Widget


In Flutter everything is a widget


Before using firebase we have to initialize it




Anonymous routes: go in page that application knows nothing about it




After adding a plugin, you need to clean and rebuild the application

```powershell
$ flutter clean
$ flutter clean android
$ flutter pub get
```


## Bloc
It allows us to separate our business logic from our presentation.
1. Bloc -> Business Logic
2. Flutter_bloc -> UI

Core of Bloc library:
- Bloc class is a container that you add events to it; every event produce a state
- BlocProvider: create Bloc instance and provides it to developer (like a builder)
- BlocListener: it can react to change in your Bloc
- BlocBuilder = create a widget based on Bloc state changes
- BlocConsumer = BlocListener + BlocBuilder



AndroidManifest.xml to change nameapp