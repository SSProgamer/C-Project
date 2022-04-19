# game design document

## Introduction

- Game Concept เป็นเกมเอาชีวิตรอดในป่า ที่เล่าเรื่องราวผ่านตัวละครเป็นมุมมองบุคคลที่1
- หมวดหมู่เกม เกมเอาชีวิตรอด
- เนื้อเรื่อง เครื่องบินที่เราโดยสารอยู่เกิดขัดข้องทำให้เครื่องบินตก แต่โชคดีที่เรารอดมาได้ และเราได้ติดต่อวิทยุของเครื่องบินเพื่อของความช่วยเหลือ หลังจากติดต่อกับหน่วยช่วยเหลือได้ความว่า เขาจะมาถึงที่เกิดเหตุใน2สัปดาห์ และเราต้องอยู่รอดให้ได้จนกว่าหน่วยกู้ภัยจะมาถึง
- บรรยายกาศของเกม จะเป็นธีมป่าลึก

## Game Structure

- โหมดเกมที่ผู้เล่นสามารถเล่นได้ โหมดเนื้อเรื่องเท่านั้น
- Engagement เราผ่านcommand line ของภาษา C
- การเล่น เป็นเกมเล่นคนเดียว
- วิธีการเล่น ตัวเกมรับคำสั่งจาก keyboard เพื่อให้เลือกทางเลือกหรือทำ action บางอย่างในสถาะการนั้นๆ

## Graphics & Sound

- มุมมองของเกม เป็นบุคคลที่ 1
- สไตล์กราฟฟิก เป็น ascii กราฟฟิก
- Animation อาจมีเล็กน้อย เช่นเดินทางเปลี่ยนโซน
- Music ถ้าใส่มาได้ก็จะมี
  
  ## Platform
- PC

## Development System

- VScode & Codebox

## Game play

- Character เราจะได้สวมบทบาทเป็น ชายที่ชื่อว่า Jack มีความรู้เกี่ยวกับป่าและรู้เรื่องคุณของสมุนไพรบางชนิด
- Story เครื่องบินที่เราโดยสารอยู่เกิดขัดข้องทำให้เครื่องบินตก แต่โชคดีที่เรารอดมาได้ และเราได้ติดต่อวิทยุของเครื่องบินเพื่อของความช่วยเหลือ หลังจากติดต่อกับหน่วยช่วยเหลือได้ความว่า เขาจะมาถึงที่เกิดเหตุใน2สัปดาห์ และเราต้องอยู่รอดให้ได้จนกว่าหน่วยกู้ภัยจะมาถึง เราได้ตัดสินใจเก็บสัมภาระออกจากเครื่องบิน ไปตั้งที่พักห่างจากเครื่องบิน 1-2 กิโล เพื่อความปลอดภัย 
- Objective เป้าหมายของการชนะคือ การเอาตัวรอดให้ได้ตามวันที่กำหนด เมื่อถึงวันที่กำหนดต้องเดินทางไปที่จุดนั้นพบเพื่อออกจากป่า การแพ้ในเกม HPของเราลดจนเหลือ 0 หรือ ไม่ได้ไปตามจุดนั้นพบในวันนีัน
- Core Game Mechanic เราต้องสำรวจป่าเพื่อหาของมาให้เราไม่อดตาย โดยการสำรวจแต่ละครั้งเราจะถูกสุ่มของที่จะได้ และจะได้ไอเทมบางอย่างเยอะเป็นพิเศษขึ้นอยู่กับอีเว้น และผู้เล่นต้องจัดการกับทรัพยากรรที่มีเพื่อให้ถึงจุดหมายของเกม
- Level Design map อาจจะใหญ่ประมาณ 20*20
- Progression เราจะใส่ระบบสุ่มอีเว้น ทำให้ความรู้ในการเล่นแต่ละรอบต่างกันเพราะสิ่งที่เจออาจจะต่างกัน
- Enemy มี 2 แบบ คือสัตร์กินพืชและสัตว์กินเนื้อ โดยที่สัตว์กินพืชจะไม่ทำร้ายเรามันมักจะหนี ส่วนสัตว์กินเนื้อจะทำร้ายเราและเราต้องหนีหรือไม่ก็ต้องสู้กลับ
- Game Flow 
  

# Flowchart ภาค 2

```mermaid
flowchart TD
start(Start Game)
endgame(End Game)
stamina(Stamina)

start ---> setday[days = 0] ---> setwin[win = 0] ---> hp[HP = 10] ---> stamina[Stamina = 10] ---> checkday{days >= 28}
checkday --yes--> win[win = 1] ---> endgame
checkday -- no --> choose[\What to do\]
choose -- Exploring --> exploring[[Exploring]]
exploring ---> first[[First Event]] ---> checkexploring{Stamina <= 0} -- yes --> stamina10
choose -- Rest --> rest[[Rest]] --->stamina10[stamina = 10]
choose -- Crafting --> crafting[[Crafting]] ---> stamina_craft(stamina = stamina-2) ---> stamina10
stamina10 ---> wood{wood <= 10} --yes--> plusday
wood --no--> hpdown[hp = -10+havewood] --->plusday
plusday[days += 1] ---> checkday
hpdied[HP = 0] --> endgame
```

# Crafting
```mermaid
flowchart TD

Wood
```
- UI Flow

### energy bur
- HP บอกเลือดที่มีอยู่ตอนนี้
- Hunger บอกความหิว หากลดจนเหลือน้อยกว่า 0 จะเสีย HP ต่อ action
- Thirsty บอกความกระหายน้ำ หากลดจนเหลือน้อยกว่า 0 จะเสีย HP ต่อ action
- Stamina บอกพลังงานที่เหลืออยู่ในการสำรวจ หากลดจนเหลือน้อยกว่า 0 จะไม่สามรถสำรวจต่อได้

### Item in game
- food อาหารจำพวก ผัก(HP+) เนื้อ(HP+)
- water น้ำจากแม่น้ำ แอ่งน้ำ(S+++) น้ำยังกินไม่ได้ต้องต้มก่อน
- Crafting มีด หอก เนื้อสุก(เนื้อ+ไฟ) สลัด(ผักรวมกัน5อัน) สลัดเนื้อ(เนื้อสุก+สลัด)
- Craft material ไม้ หิน

### combat
- ต่อสู้กับสัตว์กินพืช หากเราโจมตีใส่ กวาง หากไม่สามารถฆ่าได้ใน 1-2 action มันจะหนี
- ต่อสู้กับปลา เอาหอกทิ่มที่ปลาจะมีโอกาศได้มากว่า อาวุธชนิดอื่นมาก
- ต่อสู้กับสัตว์กินเนื้อ หากเราโจมตีใส่ เสือ มันจะโจมตีกลับและผู้เล่นจะเสียลด หากเราเสียเลือดจนหมดในการต่อสู้จะตายทันที หากไม่ต้องการสู้ก็ต้องหนี
- การหนี สุ่มว่าหนีรอด ไม่รอด ถ้าไม่รอดก็เสีย HP และต้องสู้ต่อ
### explore
- การสำรวจจะให้ตัวเลือกสามเส้นทาง คือ ข้างหน้า ทางซ้าย ทางขวา
- หลังเลือกเส้นทางแล้วก็จะทำการสำรวจพื้นที่ในทางนั้น จากนั้นจะขึ้นรายละเอียดของที่ได้รับและลด Stamina ลง และหลังจากขึ้นรายละเอียดของที่ได้มาแล้ว มีโอกาสเจอ อีเว้น เช่น เจอกวาง,หมูป่า,เสือ,แหล่งน้ำที่มีปลา
- ของที่ได้รับจากการสำรวจ ไม้(1-2ชิ้น) หิน(1-2ชิ้น) ผัก(0-2ชิ้น)
- map จะมีแบบป่าไม้ แอ่งน้ำ(น้ำ,ปลา) แม่น้ำ(น้ำ,ปลา) ป่ารก(มีโอกาสเจอผักมาก)

## Team
1. นายชาติณโยดม วิบูลย์พานิช 64070021
2. นายณัฐดนัย ปลื้มใจ 64070029
3. นายธนวัฒน์ ศรีโท 64070044
4. นายวัชรวีร์ ศรีพิบูลย์ 64070101

## Timeline
- วันเริ่ม Project 14 เมษยน
- ระยะเวลาการพัฒนาเกม สอง-สามอาทิตย์
```

```mermaid
flowchart TD
start(Start Game) ---> ingame(gameplay)
ingame --Status--> status(Status) --->hp
status ---> Stamina(Stamina) -- Stamina > 0 can--> explore
status ---> Hunger(Hunger) --Hunger <= 0--> hp_down(hp_down) ---> hp
status ---> Thirsty(Thirsty) --Thirsty <= 0--> hp_down(hp_down) ---> hp
status ---> combatpower(Combat Power += 1) --> combat
hp(HP <= 0) --true--> e(End Game)
campfire --Exploring--> explore(exploring) ---> way(choose way) ---> event(random event)
way ---> campfire
event ----> combat(Combat)
combat ---> fight(Fight) --win--> collectitem(Collect Item)
fight(Fight) --lose--> e
combat ---> run(Run) ---> Staminadown(Stamina Down) --> Stamina
run(Run) --Stamina <= 0--> e
event ---> Staminadown(Stamina Down)
event --day14 && location plane crash--> e(End Game)
event(random event) ----> collectitem(Collect Item) ---> Item
ingame --Item Use--> Itemuse(Item use)
Item ---> Itemuse ---> Itemuseable(Cook_food Cook_water vegetable fruit coconut herb) --->Hungerup(Hunger up) ---> Hunger
Itemuseable ---> Thirstyup(Thirsty Up) ---> Thirsty
Itemuseable ---> Stamina(Stamina Up)
Item ---> Itemcraft(Item Craft) --Choose Material--> Itemcraftable(Wood stone coconut_shells vines) -- Crafing Item --> equipment(Knives fishing_hooks coconut_shell_flasks spears bows) ---> combatpower
Item ---> Itemcook(Item Cook) ---> Itemcookable(meat water) --cook--> foodcook(Cook_food Cook_water) --->Itemuseable
ingame -- Campfire --> campfire(Campfire)
campfire(Campfire) -- Crafting ---------------------> Itemcraft(Item Craft)
campfire(Campfire) -- Cooking--> Itemcook(Item Cook)
```