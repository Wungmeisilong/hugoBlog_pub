# pretues&#43;kiel5仿真软件配合使用时需要注意的地方

不知道keil5从哪个版本开始就不支持了晶振的设置操作，我在网上搜也得到不同的答案，所以从哪个版本开始限制这就不提了，
好在这样的改变并不会形象我们使用keil5。最近在刚进阶学习stm32，用到了[pretues_8.11](/layout/variables) 仿真软
件和[keil5](/layout/variables)代码编辑器，自己把心中所得分享一下。

**别人编译编译成功的工程，我另外用[keil5](/layout/variables)打开编译为什么会失败？**

假设你拿到的别人的工程所选芯片为[stm32f103VC](/layout/variables)，那么你在另外的电脑打开[keil5](/layout/variables)，在设置里选芯片也是[stm32f103VC](/layout/variables)，如果选的芯片与工程最初选的型号不同，那编译可能会失败，接着在打勾生成.hex文件。

**pretues里没有找到[keil5](/layout/variables)里选择的芯片，能用别的芯片代替吗？**

答案是可以的，但尽量使用版本更高的芯片，使之能向下兼容，在[keil5](/layout/variables)如果选了[stm32f103VC](/layout/variables)，而pretues仿真的芯片是[stm32f103C6](/layout/variables)，那么你并不用担心芯片不对应而导致你仿真失败。

**在pretues导入.hex文件后直接开始仿真，为什么报了许多错误？**

可能原因：在选择好[.hex](/layout/variables)文件后，还必须设置晶振频率，即12MHz，如果没置会导致仿真失败，另外你不用担心选择的.hex文件路径有中文，我测过即使导入文件路径有中文也可以正常运行。


{{% attachments color="fuchsia" icon="fab fa-hackerrank" /%}}