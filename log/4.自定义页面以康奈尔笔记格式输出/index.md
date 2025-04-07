# 4.自定义页面以康奈尔笔记格式输出

<link rel="stylesheet" href="css/my-css/cornell-notes.css"> <div class="cornell-notes"> <div class="cues">

## Cues
  
- [Cues](#cues)
- [Notes](#notes)
  - [创建css文件](#创建css文件)
  - [在hugo配置中设置](#在hugo配置中设置)
  - [在markdown文档中引用](#在markdown文档中引用)
- [Summary](#summary)

**标签/提示** ：静态网页，康奈尔笔记，hugo，自定义页面输出格式。
</div>

<div class="notes">

## Notes

### 创建css文件

康奈尔笔记的布局，其中左侧是 "Cues"，右侧是 "Notes"，底部是 "Summary"，您可以使用 Flexbox 的 row 和 column 布局来实现。这里是一个 CSS 示例，它将创建一个两列的布局，左侧为 "Cues"，右侧为 "Notes"，然后在这两列下方是 "Summary"。

  首先，创建一个名为 cornell-notes.css 的 CSS 文件，并添加以下样式代码：

  ```c
  .cornell-notes {
    
    border: 1px solid #ccc;
    padding: 20px;
    margin: 20px;
    display: flex;
    flex-wrap: wrap;
  }

  .cues {
    background-image: url('icon2.svg');
    border-right: 1px solid #080808;
    flex: 1;
    padding-right: 20px;
  }

  .notes {
    background-image: url('icon1.svg');
    border-left: 1px solid #080808;
    flex: 2;
    padding-left: 20px;
  }

  .summary {
    width: 100%;
    clear: both; /* 清除浮动，确保摘要部分在下方 */
    padding-top: 20px;
    background-image:url('wwwatercolor.jpg');
    margin-top: 20px;
  }
  ```

  在这个样式中，.cornell-notes 是整个康奈尔笔记的容器，我们使用 display: flex; 和 flex-wrap: wrap; 来创建一个 Flex 容器，允许子元素根据需要换行。.cues 和 .notes 分别设置为容器的子项，并通过 flex 属性来分配空间。.summary 部分使用 width: 100%; 来确保它在 .cues 和 .notes 下方显示，并使用 clear: both; 来清除之前的浮动。

  此处分享一个免费的svg网站，[bbburst：](https://fffuel.co/)
  ![bbburst](image.png)
  在这个网站或许你可以找到适合你的背景图，用以装饰自己的康奈尔容器，此处的svg是放在css文件夹下的，所以是直接引用，如果你放在别的的放那么还请使用正确的的路径。

### 在hugo配置中设置

  接下来，确保将 cornell-notes.css 文件放置在 Hugo 站点的 static/css 目录下。然后，在 Hugo 的配置文件 config.toml 中添加对 CSS 文件的引用：

  ```c
  # config.toml
  [Params]
    # 其他参数...

  [markup]
    [markup.goldmark]
      [markup.goldmark.renderer]
        unsafe = true  # 允许在 Markdown 中使用 HTML 和 CSS
  ```

  如果使用的是code打开的项目，那么可以先在code内搜索上面的配置是否已添加，因为部分hugo主题原来就添加了这一配置。
  
### 在markdown文档中引用

  在 Markdown 文件中，你可以这样使用这些类：

  ```c
  ---
  title: "康奈尔笔记示例"
  ---

  <link rel="stylesheet" href="/css/cornell-notes.css">  <div class="cornell-notes">    <div class="cues">
  ## Cues
      - 这里是关键词和提示。
  </div>
  <div class="notes">
  ## Notes
    - 这里是详细的笔记内容。
  </div>
  <div class="summary">
  ## Summary
   - 这里是笔记的摘要。
  </div>
  </div>
  ```

 确保在 Markdown 文件中添加 <link> 标签来引入 CSS 文件，并为每个部分使用相应的类。这样，当你构建并查看 Hugo 站点时，康奈尔笔记将以正确的样式显示，其中 "Cues" 在左侧，"Notes" 在右侧，"Summary" 在底部。

</div>

<div class="summary">

## Summary

 在上面我们学习了如何自定义hugo中页面的输出格式，在引用hugo主题情况下，自定义自己的页面输出格式只需要三点，即创建css文件，在config配置文件中配置相关信息，在markdown中引用。其实我们可以拓展，如果你想创建属于自己的笔记你可以参照上面的方法自制简单的笔记，希望本期内容对你有所帮助。
</div>
</div>