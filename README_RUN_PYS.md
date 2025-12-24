# run_pys_script

This runner executes `.pys` scripts (the project's PyScript language) using the embedded Python environment and the `ScriptInterpreter`.

Prerequisites:
- Python with `numpy` and `pandas` available (system Python or project `.venv`).

Build:

    cmake -S . -B build
    cmake --build build -j

Run:

    ./build/run_pys_script python/huge_complex_program.pys 100

Notes:
- `run_pys_script` will start the embedded Python interpreter and execute the `.pys` program.
- The .pys program uses `import numpy as np` and `import pandas as pd` — install those packages in your Python environment.
- The runner sets `sys.argv` so the script may read command-line parameters.
