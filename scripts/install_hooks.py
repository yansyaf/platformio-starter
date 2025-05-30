import os

def install_git_hook():
    hooks_dir = os.path.join(".git", "hooks")
    hook_path = os.path.join(hooks_dir, "pre-commit")

    # Ensure hooks dir exists
    os.makedirs(hooks_dir, exist_ok=True)

    hook_content = """#!/bin/bash
# Run the update version script before commit
./scripts/update_version.sh
git add src/config.h
"""

    # Write or overwrite the hook file
    with open(hook_path, "w") as f:
        f.write(hook_content)

    # Make it executable
    os.chmod(hook_path, 0o755)

    print("Git pre-commit hook installed or updated.")

def before_build(source, target, env):
    install_git_hook()

from SCons.Script import AlwaysBuild, Builder, DefaultEnvironment # type: ignore

env = DefaultEnvironment()

install_builder = Builder(action=before_build)
env.Append(BUILDERS={"InstallGitHooks": install_builder})

git_hook_target = env.InstallGitHooks("install_hooks", None)
AlwaysBuild(git_hook_target)
env.Depends("all", git_hook_target)
