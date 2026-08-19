# CSES Problem Set - Team Library

Official competitive programming library repository for the team **Enemy Leo used Appeal! It's super effective! Pikachu fainted! (State University of Campinas - UNICAMP)**.

This project contains our C++ solutions for the [CSES Problem Set](https://cses.fi/problemset/) and an automated generator that builds a PDF notebook.

## Team
* Pedro Assunção
* Pedro Mesquita
* Yvens Porto

## How it works?
The project uses a Python script (`gerador_cses.py`) combined with a `Makefile` to automate the entire notebook build process. The script performs the following operations:
1. Scans the `src/` folder for source codes (C++) organized by topics.
2. Automatically downloads and caches the corresponding problem statements directly from the CSES website.
3. Filters the C++ codes, automatically removing competitive programming boilerplate (includes, defines, fast I/O macros, and trivial mains) to save space and paper.
4. Injects everything into an optimized LaTeX template and compiles the final PDF.

## Folder Structure
To keep the repository clean, the architecture is divided as follows:
* `src/`: Your folders with the C++ solutions (e.g., `DynamicProgramming/`, `GraphAlgorithms/`).
* `assets/`: Images and logos used on the notebook's cover.
* `enunciados/`: Cache folder where downloaded CSES problem statements are saved.
* `latex/`: Build folder. The Python script generates the `.tex` file in here, and LaTeX does all the messy compilation here, keeping the root of the project clean.
* `gerador_cses.py`: The "engine" of the project.
* `Makefile`: The maestro that executes the commands.

## Commands

All interaction with the generator is done via the `make` command in your terminal, at the root of the project.

### Generate the Notebook
```bash
make caderno
```

### Clean Build Cache
```bash
make clean
```