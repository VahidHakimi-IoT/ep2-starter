# My ceiling — person detection on the ESP32-S3

| Image size | My prediction | Measured | FPS | Accuracy |
|---|---:|---:|---:|---:|
| 96 × 96 | Guess: 90 ms | 4377 ms | 0.2 FPS | 80% |
| 160 × 160 | 96 px time × 2.8 = 12,255.6 ms | 12,140 ms | 0.1 FPS | 83% |
| 48 × 48 | 96 px time ÷ 4 = 1,094.25 ms | 1,038 ms | 1 FPS | 66.1% |

## Which budget breaks first — time or memory?

1. A doorbell: decide "person or not" within 1 second of the button press, at 96 × 96.  
   → **time** — Inference takes 4.377 seconds, which is longer than the 1-second requirement.

2. A people counter: keeps one 320 × 240 colour photo in memory and checks it once a minute.  
   → **memory** — An RGB image of this size requires 230,400 bytes of memory, putting pressure on the ESP32-S3's limited RAM.

3. Your team's project: which budget is tighter for your model, and why?  
   → **time** — Our 96 × 96 inference takes 4.377 seconds, so the model is too slow for applications requiring a quick response.

