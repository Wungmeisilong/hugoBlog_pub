# 3.github和atomgit的混合使用，哪些是值得注意的？

## 一台电脑如何使用多个远程仓库？

- 下载好git，并做好相关的配置
- 关联github仓库
  - 创建github仓库
  - 克隆仓库到本地
  
```git
  git clone <你的远程仓库URL>
```

创建多个 SSH 密钥对涉及到在本地生成多个公钥和私钥文件，并将公钥添加到你想要访问的远程服务器上。以下是详细步骤：

打开终端：
打开你的终端（在 macOS 或 Linux 上）或 Git Bash（在 Windows 上）。

导航到 SSH 目录：
使用 cd 命令切换到你的 SSH 目录，通常是 ~/.ssh。

```cd ~/.ssh```
生成新的 SSH 密钥对：
使用 ssh-keygen 命令生成新的密钥对。每次运行此命令时，你都可以指定不同的文件名，以便区分不同的密钥对。例如，为 GitHub 生成的密钥对可能命名为 id_rsa_github，为 GitLab 生成的密钥对可能命名为 id_rsa_gitlab。

```ssh-keygen -t rsa -b 4096 -C "your_email@example.com" -f id_rsa_github```
重复上述步骤，为其他服务生成密钥对，只需更改文件名即可。例如：

```ssh-keygen -t rsa -b 4096 -C "another_email@example.com" -f id_rsa_gitlab```

-b是指密码的长度是4096，与加密有关，-f表示要创建的ssh有关文件名

在生成密钥时，系统会提示你输入一个文件名来保存新的密钥对。如果你直接按回车键，它将使用默认的文件名（如 id_rsa）。如果你想要为每个服务使用不同的文件名，确保在命令中指定 -f 选项后跟你想要的文件名。

将公钥添加到远程服务器：
生成密钥对后，你需要将公钥（文件名后缀为 .pub）添加到远程服务器的 SSH 密钥管理界面。例如，在 GitHub 上，你可以在 Settings > SSH and GPG keys 部分添加新的公钥。

配置 SSH 配置文件：
为了确保 SSH 使用正确的密钥对连接到正确的服务器，你可以在 .ssh 目录下创建一个名为 config 的文件（如果该文件不存在的话），并为每个服务配置不同的设置。

```touch ~/.ssh/config```

然后编辑这个文件，添加以下内容：

```c
Host github.com
  User git
  IdentityFile ~/.ssh/id_rsa_github
  IdentitiesOnly yes

Host gitlab.com
  User git
  IdentityFile ~/.ssh/id_rsa_gitlab
  IdentitiesOnly yes
```

这里的 Host 是你为每个服务设置的别名，User 是 Git 服务的默认用户名（通常是 git），IdentityFile 是你的私钥文件的路径。

测试 SSH 连接：
使用 ssh -T 命令测试与远程服务器的连接。例如：

```c
ssh -T git@github.com
ssh -T git@gitlab.com
```

如果一切设置正确，你应该会看到一条欢迎消息，表明你已经成功通过 SSH 密钥验证。

## 当我有连个github账户时，当我用同一台电脑推送的时候如何区分是那个推送的

[推荐文章](https://blog.csdn.net/Kingson_Wu/article/details/38960559)

答案：

首先是克隆下来两个项目一个为test_A,一个为test_B，假设有一个账户是A，另一个是B，而且A账户的邮箱是设置为全局的，即用了这条命令：

```c
git config --global user.name "A"

git config --global user.email A@qq.com
#假设这里的邮箱是QQ
```

那么在在text_A中不作任何修改，在text_B中添加如下命令即可：

```c
git config  user.name "B"

git config user.email B@qq.com
#假设这里的邮箱是QQ
```

## 遇到的一些问题

问题一

---
解决Git上传代码error: failed to push some refs to ‘xxx‘hint:(e.g., ‘git pull ...‘) before pushing again错误

---
[推荐文章](https://blog.csdn.net/qq_43265673/article/details/107392047)

问题二

---
【Git】错误：权限被拒绝（公钥）(Permission denied (publickey).)

---

[推荐文章](https://blog.csdn.net/weixin_42282187/article/details/124820546?spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2%25!E(MISSING)default%25!E(MISSING)CTRLIST%25!E(MISSING)Rate-2-124820546-blog-100894172.235%25!E(MISSING)v43%25!E(MISSING)pc_blog_bottom_relevance_base8&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%25!E(MISSING)default%25!E(MISSING)CTRLIST%25!E(MISSING)Rate-2-124820546-blog-100894172.235%25!E(MISSING)v43%25!E(MISSING)pc_blog_bottom_relevance_base8&utm_relevant_index=5)2)

问题三

---
解决Git上传代码error: failed to push some refs to ‘xxx‘hint:(e.g., ‘git pull ...‘) before pushing again错误

---
[推荐文章](https://blog.csdn.net/qq_43265673/article/details/107392047)

{{% attachments color="fuchsia" icon="fab fa-hackerrank" /%}}