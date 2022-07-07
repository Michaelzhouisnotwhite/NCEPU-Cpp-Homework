# %%
import os
import zipfile

start_dir = os.getcwd()
target_dir = os.path.dirname(os.getcwd())
target = os.path.join(target_dir, "第" + start_dir[-1] + "次作业 120191080318 周袁卿.zip")
# %%
zfile = zipfile.ZipFile(target, "w")

for dir_or_files in os.listdir(start_dir):
    if os.path.isdir(dir_or_files):
        dir_path = os.path.join(start_dir, dir_or_files)

        for file in os.listdir(dir_path):
            if file.endswith(".cpp"):
                os.chdir(dir_path)
                zfile.write(file)
                os.chdir(start_dir)
    elif dir_or_files.endswith(".cpp"):
        zfile.write(dir_or_files)

zfile.close()
# %%
