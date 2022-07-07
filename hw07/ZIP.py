# %%
import os
import zipfile
import sys

start_dir = os.getcwd()
target_dir = os.path.dirname(os.getcwd())

num = input("enter a num for your file:")
target = os.path.join(target_dir, "第" + num + "次作业 120191080318 周袁卿.zip")
# %%
zfile = zipfile.ZipFile(target, "w")
os.chdir(target_dir)


def gci(filepath):
    # 遍历filepath下所有文件，包括子目录
    files = os.listdir(filepath)
    for fi in files:
        if fi == "CompilerIdCXX" or fi == "out":
            continue
        fi_d = os.path.join(filepath, fi)
        # fi_d = os.path.join(os.path.dirname(fi), fi)
        if os.path.isdir(fi_d):
            # os.chdir(fi_d)
            gci(fi_d)
        else:
            #  apath = os.path.join(filepath,fi_d)
            apath = os.path.join(filepath, fi_d)
            if fi_d.endswith('.cpp') or fi_d.endswith('.h'):
                print(apath)
                if os.path.split((os.path.dirname(fi_d)))[1] == 'src':
                    base_double_dir = os.path.split(os.path.dirname(fi_d))[0]
                    os.chdir(os.path.dirname(base_double_dir))
                    c_file_path = os.path.join(os.path.split(os.path.dirname(fi_d))[1], os.path.split(fi_d)[1])
                    c_file_path_2 = os.path.join(os.path.split(base_double_dir)[1], c_file_path)
                    zfile.write(c_file_path_2)
                else:
                    os.chdir(os.path.split(os.path.dirname(fi_d))[0])
                    c_file_path = os.path.join(os.path.split(os.path.dirname(fi_d))[
                                              1], os.path.split(fi_d)[1])
                    zfile.write(c_file_path)
                os.chdir(filepath)

# %%
if __name__ == "__main__":
    gci(start_dir)
    zfile.close()
    os.system("pause")
