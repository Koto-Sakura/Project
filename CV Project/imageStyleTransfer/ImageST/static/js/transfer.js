// transfer.js

document.getElementById('image-input').addEventListener('change', function(event) {
    const file = event.target.files[0];
    if (file) {
        const reader = new FileReader();
        reader.onloadend = function() {
            const img = document.getElementById('input-image');
            img.src = reader.result;
            img.style.display = 'block';
            document.getElementById('upload-prompt').style.display = 'none'; // 隐藏提示文本

            // 调整容器大小以适应图片
            const container = document.querySelector('.input-image-container');
            container.style.width = 'auto';
            container.style.height = 'auto';

            img.onload = function() {
                const maxWidth = 400; // 最大宽度
                const maxHeight = 400; // 最大高度
                let scale = 1;

                if (img.width > maxWidth || img.height > maxHeight) {
                    if (img.width / img.height > maxWidth / maxHeight) {
                        scale = maxWidth / img.width;
                    } else {
                        scale = maxHeight / img.height;
                    }
                }

                container.style.width = img.width * scale + 'px';
                container.style.height = img.height * scale + 'px';
            };
        };
        reader.readAsDataURL(file);
    }
});

document.getElementById('upload-form').addEventListener('submit', function(event) {
    event.preventDefault();
    const formData = new FormData(this);
    const csrfToken = document.querySelector('meta[name=csrf-token]').content;

    fetch(this.action, {
        method: 'POST',
        body: formData,
        headers: {
            'X-CSRFToken': csrfToken
        }
    })
    .then(response => response.json())
    .then(data => {
        if (data.processed_file_url) {
            const outputImg = document.getElementById('output-image');
            outputImg.src = data.processed_file_url;
            outputImg.style.display = 'block';

            // 调整输出容器大小以适应图片
            const outputContainer = document.querySelector('.output-image-container');
            outputContainer.style.width = 'auto';
            outputContainer.style.height = 'auto';

            outputImg.onload = function() {
                const maxWidth = 400; // 最大宽度
                const maxHeight = 400; // 最大高度
                let scale = 1;

                if (outputImg.width > maxWidth || outputImg.height > maxHeight) {
                    if (outputImg.width / outputImg.height > maxWidth / maxHeight) {
                        scale = maxWidth / outputImg.width;
                    } else {
                        scale = maxHeight / outputImg.height;
                    }
                }

                outputContainer.style.width = outputImg.width * scale + 'px';
                outputContainer.style.height = outputImg.height * scale + 'px';
            };

            // 添加下载按钮的点击事件
            document.querySelector('.download-button').addEventListener('click', downloadImage);
        } else {
            alert('Error processing file');
        }
    })
    .catch(error => console.error('Error:', error));
});

function downloadImage() {
    const outputImg = document.getElementById('output-image');
    if (outputImg.src) {
        const a = document.createElement('a');
        a.href = outputImg.src;
        a.download = 'processed_image.jpg'; // 设置下载文件名
        document.body.appendChild(a);
        a.click();
        document.body.removeChild(a);
    } else {
        alert('No processed image available to download.');
    }
}