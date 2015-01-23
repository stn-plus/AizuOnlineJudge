# Problem Volume0 - 0090: {{{
# Overlaps of Seals
#
# 1辺の長さが10の正方形の折り紙に半径1の円形のシールを n 枚貼ります。シールは重
# ねて貼ることができます。シールを貼る位置の座標を読み込んで、折り紙上でもっと
# も多くシールが重なっている場所(シールが１枚だけでも"重なっている"とする)での
# シールの枚数を出力して終了するプログラムを作成してください。ただし、n は100以
# 下とします。
# Input
#
# 折り紙の左下を原点とした x, y 座標を与えます。この x, y を円の中心としてシー
# ルを貼ることとします。円の中心が折り紙の外に出ることはありません。
#
# 複数のデータセットが与えられます。各データセットは以下のような形式です。
#
# n   (シールの枚数)
# x1,y1（1枚目のシールの中心座標：全て実数）
# x2,y2（2枚目のシールの中心座標：全て実数）
# x3,y3（3枚目のシールの中心座標：全て実数）
#       ：
#       ：
# xn,yn（n 枚目のシールの中心座標：全て実数）
#
# n が 0 のとき、入力の最後とします。
# Output
#
# 各データセットに対し、折り紙上で最も多くシールが重なっている場所でのシールの
# 枚数（整数）を出力して下さい。
#
# Sample Input
#
# 15
# 3.14979,8.51743
# 2.39506,3.84915
# 2.68432,5.39095
# 5.61904,9.16332
# 7.85653,4.75593
# 2.84021,5.41511
# 1.79500,8.59211
# 7.55389,8.17604
# 4.70665,4.66125
# 1.63470,4.42538
# 7.34959,4.61981
# 5.09003,8.11122
# 5.24373,1.30066
# 0.13517,1.83659
# 7.57313,1.58150
# 0
#
# Output for the Sample Input
#
# 4
#
# Hint
#
# 入力例のようにシールを貼った図です。円はシール、数字は入力例の行数を表してい
# ます。 点(2.3,4.6)では、入力例の2行目、3行目、6行目、10行目の4枚のシールが重
# なっています。
# }}}

class Circle
  attr_accessor :x, :y
  def initialize(x=0.0, y=0.0)
    @x, @y = x.to_f, y.to_f
  end

  def distance(c)
    Math::hypot(c.x-@x, c.y-@y)
  end
  def crosspoints(c)
    d = distance(c)
    a = Math::atan2(c.y-@y, c.x-@x)
    # 1 is radius (of each circle)
    dec = Math::acos((d**2 + 1**2 - 1**2)/(2*d*1))
    [dec, -dec].map do |dec|
      [@x + 1*Math::cos(a-dec), @y + 1*Math::sin(a-dec)]
    end
  end
  def cover?(x, y)
    Math::hypot(x-@x, y-@y) <= 1.0
  end
end

while (n = gets.to_i) != 0
  circles = []
  allCrosspoints = []
  answer = 1

  n.times do |t|
    # omajinai
    x, y = gets.chomp.split(",").map{|n| n.to_f}
    circles[t] = Circle.new(x, y)
    # should use circles.push(Circle.new(x, y))
  end

  circles.each do |c1|
    circles.each do |c2|
      next if c1 == c2
      next if c1.distance(c2) > 2.0
      # p c1, c2

      allCrosspoints.push(c1.crosspoints(c2))
      # p debug, allCrosspoints, "- - -"
    end
  end

  allCrosspoints.flatten(1).each do |x, y|
    # p x, y
    covercnt = 0
    circles.each do |c|
      covercnt += 1 if c.cover?(x, y)
    end
    answer = covercnt if covercnt > answer
  end
  puts answer
end
# vim: fdm=marker :
