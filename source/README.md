# Mã nguồn minh hoạ: DRY & SRP (C++17)

Biên dịch được với C++11 trở lên (đã thử với `-std=c++11`, `-std=c++14`, `-std=c++17`). Nên thêm cờ `-std=c++17` nếu sử dụng trình biên dịch cũ.
Chạy tất cả: `./run_all.sh`. Chạy riêng một ví dụ, ví dụ:

    g++ -std=c++17 -Ipart1_dry/before part1_dry/before/*.cpp -o demo && ./demo

| Thư mục | Nội dung | Mục báo cáo |
|---|---|---|
| `part1_dry/before`, `after` | Chính sách giá lặp ở 3 nơi, rồi gom vào `PricingPolicy` | 2.1.5 |
| `part1_srp/before`, `after` | `Employee` phục vụ 3 actor, rồi tách thành 4 lớp | 2.2.6 |
| `part2_dry_overuse/over_abstracted`, `simple` | `LineFormatter` nhiều cờ và bản đơn giản | 3.1 |
| `part2_dry_acceptable_duplication/v1_today`, `v2_after_evolution`, `v2_merged_wrong` | Hai chính sách hoàn tiền | 3.1 |
| `part2_srp_overuse/over_engineered`, `simple` | Mượn sách: 10 kiểu so với 1 lớp | 3.2 |
| `part2_srp_acceptable_grouping` | `ShoppingCart`: nhiều phương thức, một trách nhiệm | 3.2 |
| `part3_code_review/scenario1_shared_validation` | Kịch bản 1 | 4 |
| `part3_code_review/scenario5_order_service/before`, `after` | Kịch bản 5 | 4 |

Kịch bản 2, 3, 4 của Phần 3 chỉ có đoạn mã ngắn ngay trong báo cáo.
