document.addEventListener("DOMContentLoaded", () => {
    
    const memberForm = document.getElementById("member-form");
    const feedbackDiv = document.getElementById("feedback-message");
    memberForm.addEventListener("submit", async (event) => {
        event.preventDefault(); 
        const name = document.getElementById("name").value;
        const memberID = document.getElementById("member-id").value;
        const memberType = document.getElementById("member-type").value;
        const data = {
            name: name,
            id: memberID,
            type: memberType
        };
        feedbackDiv.textContent = "";
        feedbackDiv.className = "";
        try {
            const response = await fetch("http://localhost:8080/add-member", {
                method: "POST",
                headers: {
                    "Content-Type": "application/json",
                },
                body: JSON.stringify(data), 
            });
            const result = await response.json();

            if (response.ok) {
                feedbackDiv.textContent = result.message;
                feedbackDiv.className = "success";
                memberForm.reset();
            } else {
                feedbackDiv.textContent = "LỖI TỪ SERVER: " + result.message;
                feedbackDiv.className = "error";
            }

        } catch (error) {
            console.error("Lỗi kết nối:", error);
            feedbackDiv.textContent = "LỖI: Không thể kết nối đến máy chủ C++. Bạn đã chạy backend chưa?";
            feedbackDiv.className = "error";
        }
    });
});