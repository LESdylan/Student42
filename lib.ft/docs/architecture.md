# Overall Project Architecture
## Modular Programming
---
- The project is divided into modules (e.g., ctype, list, memory, string, io), each responsible for specific functionality.
- Code reuse: These modules can be reused in other projects, making the codebase more flexible and maintainable.
- Each directory and file has a clear responsibility, which minimizes the risk of interdependencies and promotes maintainability.
## Separation of Concerns (SoC)
---
> The project is organized by categories of tasks (e.g., src, test, docs, automation scripts). Each folder or file has a distinct responsibility, reducing the risk of unwanted dependencies between different parts of the project.

## Continuous Integration / Continuous Deployment (CI/CD)
> Integrating a Makefile into the project facilitates continuous integration, and combining it with scripts automates various tasks related to building, testing, and deployment.

- Automation of repetitive tasks: This eliminates manual work and ensures consistency.
- Risk reduction: By automating the testing process, especially with well-constructed tests, the risk of human error is minimized when verifying the correctness of the implementation.
## Test-Driven Development (TDD)
---
- The project structure aligns with the principles of Test-Driven Development (TDD), where tests are written before or alongside the code. This ensures that the application behaves as expected and allows for easier refactoring.
- Testability: The modular structure and clear separation of concerns make the project easier to test, which increases the reliability and maintainability of the code.

## My tree project
---
```bash
├── Makefile
├── README.md
├── docs
│   ├── architecture.md
│   ├── installation.md
│   └── usage.md
├── externals
│   ├── a.out
│   ├── ctype
│   │   ├── README.md
│   │   ├── *.c
│   ├── include
│   │   ├── README.md
│   │   ├── io.h
│   │   ├── list.h
│   │   ├── memory.h
│   │   ├── mylib.h
│   │   ├── string.h
│   │   └── type.h
│   ├── io
│   │   ├── README.md
│   │   ├── *.c
│   ├── list
│   │   ├── README.md
│   │   ├── *.c
│   ├── memory
│   │   ├── README.md
│   │   ├── *.c
│   └── string
│       ├── README.md
│       ├── *.c
├── scripts
│   ├── *.sh
└── tests
    ├── ctype
    │   └── test_is.c
    ├── list
    │   └── test_list.c
    └── string
        └── test_string.c

```