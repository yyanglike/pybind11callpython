# run_python_script

Small helper to run Python scripts via the embedded Python interpreter in this project.

Build:

    cmake -S . -B build
    cmake --build build -j

Run:

    ./build/run_python_script python/huge_complex_script.py --nums 5 7 11 --more 13 17 --factor 3 --out /tmp/huge.json --flag

Notes:
- `run_python_script` sets `sys.argv` for the executed script from the command line arguments.
- The script prints structured JSON to stdout and writes a summary file to `--out`.
