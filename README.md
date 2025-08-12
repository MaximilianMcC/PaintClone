# Paint clone
Paint clone written with SFML and C++ 

## Development setup (vscode)
1. Go to the sfml [download page](https://www.sfml-dev.org/download/sfml/3.0.0/#windows)
1. Download the **32bit** cpp **17** version (should be top link)
1. Copy and paste the `include` and `lib` directories into `./PaintClone/PaintClone` (same directory as the .`vcxproj`)
1. From the `bin` folder, paste all `dll` files that end with `-d` into `./PaintClone/PaintClone/Debug/`
1. From the `bin` folder, paste all `dll` files that do not end with `-d` into `./PaintClone/PaintClone/Release/`
1. `F5`

# Feature Checklist

## Section 1: Basic Features
- [ ] **Mouse-based drawing**
  - [ ] Draw shapes with the mouse (Box, Ellipse, Line)
  - [x] Click-and-hold drawing (no 'placing' shapes)
  - [x] Shapes resize while holding mouse button (scale from top left)
  - [x] Shapes persist after being drawn
- [ ] **Required Shapes**
  - [x] Box
  - [x] Ellipse
  - [ ] Line (adjustable thickness)
- [ ] **Menu Options**
  - [x] Change current tool (Box, Ellipse, Line)
  - [ ] Change fill colour (any `sf::Color` basic colour)
  - [ ] Change width of selected tool  
    - [ ] Applies to line thickness  
    - [ ] Applies to outline thickness for other shapes

## Section 2: Advanced Features
- [ ] **Saving and Loading**
  - [ ] Save image to file system (correct extension)
  - [ ] Load image with file dialog (no stretching or distortion)
- [ ] **Polygon Tool**
  - [ ] Draw custom n-gons  
  - [ ] Multiple inputs (e.g., left click for points, right click to connect)
- [ ] **Stamp Tool**
  - [ ] Load image via dialog
  - [ ] Stamp image onto canvas
  - [ ] Maintain proportions (no cropping/distortion)
  - [ ] Place multiple stamps in window
- [ ] **Colour Dialog**
  - [x] Colour picker with gradient
  - [ ] Applies to all tools (except stamp, file save/load)

## Section 3: Project Technical Requirements
- [ ] **Build Quality**
  - [x] Builds in Debug and Release with no warnings/errors at Level 3
  - [x] Include all source files and required external data
- [x] **Coding Standards**
  - [x] Clear, concise comments
  - [x] Good variable naming
  - [x] Minimise repetitive code
  - [x] Clear logic flow
- [ ] **Runtime Quality**
  - [ ] No memory leaks
  - [ ] No bugs
  - [x] No crashes
- [x] **Technical Features**
  - [x] Effective use of C++
  - [x] Object-Oriented Programming
  - [x] SFML framework usage
- [x] **Interface Features**
  - [x] Readme with clear instructions
  - [x] Intuitive, clear controls
  - [x] Effective use of screen space

## Section 4: Submission Guidelines
- [ ] **Naming Conventions**
  - [ ] Correct folder/file naming as per example
  - [ ] Include all necessary files in `.zip`
- [ ] **Release Build**
  - [ ] Release executable zipped with all required files
  - [ ] Correct folder structure
- [ ] **Submission**
  - [ ] Submit via MyLearn as `.zip` file

## Section 5: Assessment Criteria (Self-Check)
- [ ] Basic features complete and functional
- [ ] Advanced features implemented
- [ ] High coding standards met
- [ ] Solution builds without modification
- [ ] Build is stable, complete, and well-structured