# My ceiling — person detection on the ESP32-S3

<!--
Session 6. Fill this in as you go, then commit it as "FINAL: my ceiling".
- 96 × 96: GUESS the time before you flash, then write the measured time.
- 160 × 160 and 48 × 48: PREDICT from your measured 96 px time
  (× 2.8 and ÷ 4 — slide "More pixels, more stops"), then measure.
- Accuracy: the validation accuracy on Edge Impulse's "Transfer learning" page
  after training (for 96 px it is already there in the cloned project).
- The three questions at the bottom are the homework: answer each with
  "time" or "memory" and one reason — from your measurements or the slides.
-->

| Image size | My prediction             | Measured | FPS | Accuracy |
|------------|---------------------------|----------|-----|----------|
| 96 × 96    | guess: 90 ms             | 4377 ms   | 0.2 FPS | 80 %    |
| 160 × 160  | 96 px time × 2.8 = 270 ms | 12140 ms   | 0.1 FPS| 83 %    |
| 48 × 48    | 96 px time ÷ 4 = 24 ms   | 1038 ms   | 1.0 | 80 %    |

## Which budget breaks first — time or memory?

1. A doorbell: decide "person or not" within 1 second of the button press, at 96 × 96.
   → ...
2. A people counter: keeps one 320 × 240 colour photo in memory and checks it once a minute.
   → ...
3. Your team's project: which budget is tighter for your model, and why?
   → ...
