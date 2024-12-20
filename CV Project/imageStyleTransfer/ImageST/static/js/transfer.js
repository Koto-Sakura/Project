document.addEventListener('DOMContentLoaded', function() {

    const styleRadios = document.querySelectorAll('input[name="style-select"]');
    if (!styleRadios) {
        console.error('Elements with name "style-select" not found');
        return;
    }

    styleRadios.forEach(radio => {
        radio.addEventListener('change', function(event) {
            const pixelSlider = document.querySelector('.pixel-slider');
            if (!pixelSlider) {
                console.error('Element with class ".pixel-slider" not found');
                return;
            }

            console.log(event.target.value);
            if (event.target.value === 'pixel') {
                pixelSlider.style.display = 'block';
            } else {
                pixelSlider.style.display = 'none';
            }
        });
    });

    const pixelLevelInput = document.getElementById('pixel-level');
    const pixelValueDisplay = document.getElementById('pixel-value-display');

    if (pixelLevelInput && pixelValueDisplay) {
        pixelLevelInput.addEventListener('input', function(event) {
            pixelValueDisplay.textContent = `当前值: ${event.target.value}`;
        });
    }

    const uploadForm = document.getElementById('upload-form');
    if (!uploadForm) {
        console.error('Element with ID "upload-form" not found');
        return;
    }

    const imageInput = document.getElementById('image-input');
    const inputImage = document.getElementById('input-image');
    const uploadPrompt = document.getElementById('upload-prompt');

    if (imageInput && inputImage && uploadPrompt) {
        imageInput.addEventListener('change', function(event) {
            const file = event.target.files[0];
            if (file) {
                const reader = new FileReader();
                reader.onload = function(e) {
                    inputImage.src = e.target.result;
                    inputImage.style.display = 'block';
                    uploadPrompt.style.display = 'none';

                    // 调整图片大小以适应容器
                    inputImage.onload = function() {
                        resizeImage(inputImage, 620, 460);
                    };
                };
                reader.readAsDataURL(file);
            }
        });
    }

    uploadForm.addEventListener('submit', function(event) {
        event.preventDefault();
        console.log('Form submitted');

        // 显示遮罩层和加载动画
        const mask = document.getElementById('mask');
        const loadingSpinner = document.getElementById('loading-spinner');
        mask.style.display = 'flex';
        loadingSpinner.style.display = 'block';

        const formData = new FormData(this);
        const csrfToken = document.querySelector('meta[name=csrf-token]').content;

        // 获取选中的单选框值
        const selectedStyle = document.querySelector('input[name="style-select"]:checked').value;

        // 如果选择了像素化风格，则获取像素化程度
        if (selectedStyle === 'pixel') {
            const pixelLevel = document.getElementById('pixel-level').value;
            formData.append('pixel-level', pixelLevel);
        }

        formData.append('style-select', selectedStyle);

        fetch(this.action, {
            method: 'POST',
            body: formData,
            headers: {
                'X-CSRFToken': csrfToken
            }
        })
        .then(response => response.json())
        .then(data => {
            console.log('Response received:', data);
            if (data.processed_file_url) {
                const outputImg = document.getElementById('output-image');
                outputImg.src = data.processed_file_url;
                outputImg.style.display = 'block';

                // 调整图片大小以适应容器
                outputImg.onload = function() {
                    resizeImage(outputImg, 640, 460);
                };

                // 添加下载按钮的点击事件
                document.querySelector('.download-button').addEventListener('click', downloadImage);

                // 添加点击放大事件
                outputImg.addEventListener('click', function() {
                    showModal(outputImg.src);
                });
            } else {
                alert('Error processing file');
            }

            // 隐藏遮罩层和加载动画
            mask.style.display = 'none';
            loadingSpinner.style.display = 'none';
        })
        .catch(error => {
            console.error('Error:', error);
            // 隐藏遮罩层和加载动画
            mask.style.display = 'none';
            loadingSpinner.style.display = 'none';
        });
    });

    function downloadImage() {
        console.log('Download button clicked');
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

    function showModal(imageSrc) {
        // 创建模态框
        const modal = document.createElement('div');
        modal.className = 'modal';
        modal.style.position = 'fixed';
        modal.style.top = '0';
        modal.style.left = '0';
        modal.style.width = '100%';
        modal.style.height = '100%';
        modal.style.backgroundColor = 'rgba(0, 0, 0, 0.8)';
        modal.style.display = 'flex';
        modal.style.justifyContent = 'center';
        modal.style.alignItems = 'center';
        modal.style.zIndex = '1000';

        // 创建模态框内容
        const modalContent = document.createElement('div');
        modalContent.style.position = 'relative';
        modalContent.style.maxWidth = '90%';
        modalContent.style.maxHeight = '90%';

        // 创建关闭按钮
        const closeButton = document.createElement('span');
        closeButton.className = 'close-button';
        closeButton.style.position = 'absolute';
        closeButton.style.top = '10px';
        closeButton.style.right = '10px';
        closeButton.style.color = '#fff';
        closeButton.style.fontSize = '24px';
        closeButton.style.cursor = 'pointer';
        closeButton.textContent = '×';

        // 创建图像
        const modalImage = document.createElement('img');
        modalImage.src = imageSrc;
        modalImage.style.maxWidth = '100%';
        modalImage.style.maxHeight = '100%';

        // 将内容添加到模态框
        modalContent.appendChild(closeButton);
        modalContent.appendChild(modalImage);
        modal.appendChild(modalContent);

        // 将模态框添加到文档
        document.body.appendChild(modal);

        // 关闭按钮事件
        closeButton.addEventListener('click', function() {
            document.body.removeChild(modal);
        });

        // 点击模态框外部关闭
        modal.addEventListener('click', function(event) {
            if (event.target === modal) {
                document.body.removeChild(modal);
            }
        });
    }
    function resizeImage(img, maxWidth, maxHeight) {
        let width = img.width;
        let height = img.height;

        if (width > maxWidth || height > maxHeight) {
            let ratio = Math.min(maxWidth / width, maxHeight / height);
            width *= ratio;
            height *= ratio;
        }

        img.width = width;
        img.height = height;
    }
});