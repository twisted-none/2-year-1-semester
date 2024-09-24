// Function to open the modal
function openModal(serviceType) {
    // Получаем модальное окно и заголовок
    const modal = document.getElementById("modal");
    const modalTitle = modal.querySelector("h2");
    const serviceInput = document.getElementById("serviceType");

    // Определяем заголовок в зависимости от типа услуги
    let serviceName;
    switch (serviceType) {
        case 'site-card':
            serviceName = 'сайта-визитки';
            break;
        case 'corporate-site':
            serviceName = 'корпоративного сайта';
            break;
        case 'online-store':
            serviceName = 'интернет-магазина';
            break;
        default:
            serviceName = '';
    }

    // Устанавливаем текст заголовка
    modalTitle.textContent = `Заказать разработку ${serviceName}`;

    // Устанавливаем скрытое поле формы с типом услуги
    serviceInput.value = serviceName;

    // Открываем модальное окно
    modal.style.display = "block";
}

// Function to close the modal
function closeModal() {
    const modal = document.getElementById("modal");
    modal.style.display = "none";
}

// Close the modal when clicking outside of it
window.onclick = function(event) {
    if (event.target == document.getElementById('modal')) {
        closeModal();
    }
}

// Form validation
document.getElementById('orderForm').addEventListener('submit', function(e) {
    e.preventDefault();
    
    let name = document.getElementById('name').value;
    let email = document.getElementById('email').value;
    let phone = document.getElementById('phone').value;
    let country = document.getElementById('country').value;
    let date = document.getElementById('date').value;
    let comment = document.getElementById('comment').value;

    if (name && email && phone && country && date) {
        alert('Форма успешно отправлена!');
        closeModal();
        this.reset();
    } else {
        alert('Пожалуйста, заполните все обязательные поля.');
    }
});

// Phone number mask
document.getElementById('phone').addEventListener('input', function (e) {
    var x = e.target.value.replace(/\D/g, '').match(/(\d{0,1})(\d{0,3})(\d{0,3})(\d{0,2})(\d{0,2})/);
    e.target.value = !x[2] ? x[1] : '+' + x[1] + ' (' + x[2] + ') ' + x[3] + (x[4] ? '-' + x[4] : '') + (x[5] ? '-' + x[5] : '');
});